//
// Created by song on 2022/9/28.
//

class Singleton {
private:
    Singleton() = default;

    ~Singleton() = default;

    static Singleton *instance;

    class Deleter {
        ~Deleter() {
            if (instance != nullptr) {
                delete instance;
                instance = nullptr;  // don't forget to set it to nullptr!
            }
        }
    };

    static Deleter deleter;

public:
    Singleton(const Singleton &) = delete;

    Singleton *operator=(const Singleton &) = delete;

    static Singleton *getInstance() {
        return instance;  // no need to add lock, cause instance must be initialized now
    }
};

Singleton *Singleton::instance = new Singleton;

int main() {
    auto instance = Singleton::getInstance();
}