#include "NodePostToEventLoopMaster.h"

#include "NodeJs.h"

NodePostToEventLoopMaster * NodePostToEventLoopMaster::recover_this_from_handle(uv_async_t * h) {
	return static_cast<NodePostToEventLoopMaster *>(h->data);
}

NodePostToEventLoopMaster::NodePostToEventLoopMaster(uv_loop_t * loop) {
	cb_handle_ = new uv_async_t{
		.data = this,
	};
	uv_async_init(loop, cb_handle_, [](uv_async_t * h) {
		auto this_ = recover_this_from_handle(h);
		if (this_) {
			this_->run_pending_callbacks();
		}
	});
}

NodePostToEventLoopMaster::~NodePostToEventLoopMaster() {
	cb_handle_->data = nullptr;
	uv_close(reinterpret_cast<uv_handle_t*>(cb_handle_), [](uv_handle_t* handle) {
		delete handle;
	});
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
	uv_async_send(cb_handle_);
}
