#ifndef MOD_NODEJS_NODEPOSTTOEVENTLOOPMASTER_H
#define MOD_NODEJS_NODEPOSTTOEVENTLOOPMASTER_H

#include <uv.h>

#include <functional>
#include <mutex>
#include <vector>

class NodePostToEventLoopMaster {
	static NodePostToEventLoopMaster * recover_this_from_handle(uv_async_t * h);

public:
	explicit NodePostToEventLoopMaster(uv_loop_t * loop);
	~NodePostToEventLoopMaster();

private:
	std::mutex cb_lock_;
	uv_async_t cb_handle_{};
	std::vector<std::function<void()>> cb_queue_;

	void run_pending_callbacks();

public:
	void post(std::function<void()>);
};

#endif //MOD_NODEJS_NODEPOSTTOEVENTLOOPMASTER_H
