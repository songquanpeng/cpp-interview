//
// Created by song on 2022/9/27.
// Reference: https://gist.github.com/thelinked/6997598
//

#ifndef LEARN_CPP_BLOCKING_QUEUE_H
#define LEARN_CPP_BLOCKING_QUEUE_H

#include <mutex>
#include <queue>
#include <condition_variable>

template<class T>
class BlockingQueue {
public:
    void push(T const &data) {
        {
            std::lock_guard<std::mutex> guard(mutex);
            queue.push(data);
        }
        cond.notify_one();
    }

    void pop(T &data) {
        std::unique_lock<std::mutex> guard(mutex);
        while (queue.empty()) {
            cond.wait(guard);
        }
        data = queue.front();
        queue.pop();
    }

    bool pop(T &data, int timeout_ms) {
        std::unique_lock<std::mutex> guard(mutex);
        while (queue.empty()) {
            cond.wait_for(guard, std::chrono::milliseconds(timeout_ms));
            return false;
        }
        data = queue.front();
        queue.pop();
        return true;
    }

    bool empty() const {
        std::lock_guard<std::mutex> guard(mutex);
        return queue.empty();
    }

private:
    std::queue<T> queue;
    mutable std::mutex mutex;
    std::condition_variable cond;
};

#endif //LEARN_CPP_BLOCKING_QUEUE_H
