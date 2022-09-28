#include "../concurrent/mutex.h"

// C++ 11 local static object
class Singleton {
private:
    Singleton() = default;

    ~Singleton() = default;

public:
    Singleton(const Singleton &) = delete;  // disable copy construction

    Singleton &operator=(const Singleton &) = delete;  // disable copy assignment

public:
    // if return reference here, we won't be able to assign it to a variable
    static Singleton *getInstance() {
        static Singleton instance;  // will be destruct automatically
        return &instance;
    }
};

class Singleton2 {
private:
    Singleton2() = default;

    ~Singleton2() = default;

    static Singleton2 *instance;

    class Deleter {
    public:
        ~Deleter() {
            if (instance != nullptr) {
                delete instance;
                instance = nullptr;
            }
        }
    };

    static Deleter deleter;

public:
    Singleton2(const Singleton2 &) = delete;

    Singleton &operator=(const Singleton2 &) = delete;

    static Singleton2 *getInstance() {
        if (instance == nullptr) {
            Lock lock;
            if (instance == nullptr) {
                instance = new Singleton2;
            }
        }
        return instance;
    }
};

// You can initialize it, but cannot use it directly.
Singleton2 *Singleton2::instance = nullptr;

int main() {
    auto singleton1 = Singleton::getInstance();
    auto singleton2 = Singleton2::getInstance();
}