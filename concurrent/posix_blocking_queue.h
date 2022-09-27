//
// Created by song on 2022/9/27.
//

#ifndef LEARN_CPP_POSIX_BLOCKING_QUEUE_H
#define LEARN_CPP_POSIX_BLOCKING_QUEUE_H

#include <cstdlib>
#include <pthread.h>
#include <ctime>
#include "mutex.h"
#include "condition_variable.h"

template<class T>
class BlockingQueue {
public:
    explicit BlockingQueue(int max_size = 1024) {
        if (max_size <= 0) {
            exit(-1);
        }
        max_size_ = max_size;
        array_ = new T[max_size];
        size_ = 0;
        front_ = -1;
        back_ = -1;
    }

    ~BlockingQueue() {
        mutex_.lock();
        delete[] array_;
        mutex_.unlock();
    }

    bool push(const T &item) {
        mutex_.lock();
        if (size_ >= max_size_) {
            cond_.notify_all();
            mutex_.unlock();
            return false;
        }
        back_++;
        back_ %= max_size_;
        array_[back_] = item;
        size_++;
        cond_.notify_all();
        mutex_.unlock();
        return true;
    }

    bool pop(T &item) {
        mutex_.lock();
        while (size_ <= 0) {
            if (!cond_.wait(mutex_.get())) {
                mutex_.unlock();
                return false;
            }
        }
        front_++;
        front_ %= max_size_;
        item = array_[front_];
        size_--;
        mutex_.unlock();
        return true;
    }

    bool pop(T &item, int timeout_ms) {
        mutex_.lock();
        if (size_ <= 0) {
            struct timespec abs_time = {0, 0};
            // time return the current unix timestamp (unit: seconds)
            abs_time.tv_sec = time(nullptr) + timeout_ms / 1000;
            abs_time.tv_nsec = (timeout_ms % 1000) * 1000;  // looks like it's actually millisecond not nanosecond?
            if (!cond_.wait_for(mutex_.get(), abs_time)) {
                mutex_.unlock();
                return false;
            }
        }

        if (size_ <= 0) {
            mutex_.unlock();
            return false;
        }

        front_++;
        front_ %= max_size_;
        item = array_[front_];
        size_--;
        mutex_.unlock();
        return true;
    }

    void clear() {
        mutex_.lock();
        size_ = 0;
        front_ = -1;
        back_ = -1;
        mutex_.unlock();
    }

    bool full() {
        mutex_.lock();
        if (size_ >= max_size_) {
            mutex_.unlock();
            return true;
        }
        mutex_.unlock();
        return false;
    }

    bool empty() {
        mutex_.lock();
        if (size_ == 0) {
            mutex_.unlock();
            return true;
        }
        mutex_.unlock();
        return false;
    }

    bool front(T &value) {
        mutex_.lock();
        if (size_ == 0) {
            mutex_.unlock();
            return false;
        }
        value = array_[front_];
        mutex_.unlock();
        return true;
    }

    bool back(T &value) {
        mutex_.lock();
        if (size_ == 0) {
            mutex_.unlock();
            return false;
        }
        value = array_[back_];
        mutex_.unlock();
        return true;
    }

    int size() {
        int tmp = 0;
        mutex_.lock();
        tmp = size_;
        mutex_.unlock();
        return tmp;
    }

    int max_size() {
        int tmp = 0;
        mutex_.lock();
        tmp = max_size_;
        mutex_.unlock();
        return tmp;
    }

private:
    Mutex mutex_;
    ConditionVariable cond_;

    T *array_;
    int size_{};
    int max_size_{};
    int front_{};
    int back_{};
};


#endif //LEARN_CPP_POSIX_BLOCKING_QUEUE_H
