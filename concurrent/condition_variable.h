//
// Created by song on 2022/9/27.
//

#ifndef LEARN_CPP_CONDITION_VARIABLE_H
#define LEARN_CPP_CONDITION_VARIABLE_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>


class ConditionVariable {
public:
    ConditionVariable() {
        if (pthread_cond_init(&cond_, nullptr) != 0) {
            throw std::exception();
        }
    }

    ~ConditionVariable() {
        pthread_cond_destroy(&cond_);
    }

    bool wait(pthread_mutex_t *mutex) {
        return pthread_cond_wait(&cond_, mutex) == 0;
    }

    bool wait_for(pthread_mutex_t *mutex, struct timespec t) {
        return pthread_cond_timedwait(&cond_, mutex, &t) == 0;
    }

    bool notify_one() {
        return pthread_cond_signal(&cond_) == 0;
    }

    bool notify_all() {
        return pthread_cond_broadcast(&cond_) == 0;
    }

private:
    pthread_cond_t cond_{};
};

#endif //LEARN_CPP_CONDITION_VARIABLE_H
