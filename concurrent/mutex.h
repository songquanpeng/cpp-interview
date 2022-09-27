//
// Created by song on 2022/9/24.
//

#ifndef LEARN_CPP_MUTEX_H
#define LEARN_CPP_MUTEX_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>

class Mutex {
public:
    Mutex() : mutex_() {
        // the second parameter specify the type of mutex
        if (pthread_mutex_init(&mutex_, nullptr) != 0) {
            throw std::exception();
        }
    }

    ~Mutex() {
        pthread_mutex_destroy(&mutex_);
    }

    bool lock() {
        return pthread_mutex_lock(&mutex_) == 0;
    }

    bool try_lock() {
        return pthread_mutex_trylock(&mutex_) == 0;
    }

    bool unlock() {
        return pthread_mutex_unlock(&mutex_) == 0;
    }

    pthread_mutex_t *get() {
        return &mutex_;
    }

private:
    pthread_mutex_t mutex_;
};


class MutexGuard {
public:
    explicit MutexGuard(Mutex &mutex) : mutex_(mutex) {
        mutex_.lock();
    }

    ~MutexGuard() {
        mutex_.unlock();
    }

private:
    Mutex &mutex_;  // reference type data member
};

class Lock {
public:
    Lock() : mutex() {
        mutex.lock();
    }

    ~Lock() {
        mutex.unlock();
    }

private:
    Mutex mutex;
};

#endif //LEARN_CPP_MUTEX_H
