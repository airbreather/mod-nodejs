#include "NodePostToEventLoopMaster.h"

#include "NodeJs.h"

NodePostToEventLoopMaster * NodePostToEventLoopMaster::recover_this_from_handle(uv_async_t * h) {
	auto const this_= reinterpret_cast<uint8_t *>(h) - offsetof(NodePostToEventLoopMaster, cb_handle_);
	return reinterpret_cast<NodePostToEventLoopMaster *>(this_);
}

NodePostToEventLoopMaster::NodePostToEventLoopMaster(uv_loop_t * loop) {
	uv_async_init(loop, &cb_handle_, [](uv_async_t * h) {
		recover_this_from_handle(h)->run_pending_callbacks();
	});
}

NodePostToEventLoopMaster::~NodePostToEventLoopMaster() {
	uv_close(reinterpret_cast<uv_handle_t *>(&cb_handle_), nullptr);
}

void NodePostToEventLoopMaster::run_pending_callbacks() {
	std::lock_guard l(cb_lock_);
	for (auto & cb : cb_queue_) {
		cb();
	}
	cb_queue_.clear();
}

void NodePostToEventLoopMaster::post(std::function<void()> f) {
	{
		std::lock_guard l(cb_lock_);
		cb_queue_.push_back(std::move(f));
	}
	uv_async_send(&cb_handle_);
}
