//
// Created by song on 2022/9/28.
//

#ifndef LEARN_CPP_STRING_TEST_H
#define LEARN_CPP_STRING_TEST_H

#include <cstddef>
#include <cstring>
#include <iostream>

class string {
public:
    explicit string(const char *str = nullptr) : _data(nullptr), _size(0), _capacity(0) {
        if (str == nullptr) {
            _data = new char[_capacity + 1];
        } else {
            _size = strlen(str);
            _capacity = _size;
            _data = new char[_capacity + 1];
            strcpy(_data, str);
        }
        _data[_size] = '\0';
    }

    explicit string(size_t n, char c = ' ') : _size(n), _capacity(n) {
        _data = new char[_capacity + 1];
        memset(_data, c, _size);
        _data[_size] = '\0';
    }

    // copy constructor
    string(const string &other) {
        _size = other.size();
        _capacity = _size;
        _data = new char[_capacity + 1];
        strcpy(_data, other.data());
    }

    // move constructor
    string(string &&other) noexcept {
        _data = other.data();
        _size = other.size();
        _capacity = _size;
        other.data() = nullptr;
    }

    // copy assignment operator
    string &operator=(const string &other) {
        if (this != &other) {  // in case self assignment
            string tmp(other);
            char *tmp_data = tmp.data();
            tmp.data() = _data;
            _data = tmp_data;

            // another solution
            // delete[] _data;
            // _data = nullptr;
            // _size = other.size();
            // _capacity = _size;
            // _data = new char[_capacity + 1];
            // strcpy(_data, other.data());
        }
        return *this;  // for continuous assignment
    }

    // move assignment operator
    string &operator=(string &&other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other.data();
            _size = other.size();
            other.data() = nullptr;
            _capacity = _size;
        }
        return *this;
    }

    // destructor
    ~string() {
        delete[] _data;
    }

public:
    friend std::ostream &operator<<(std::ostream &os, const string &s);

    size_t size() const {
        return _size;
    }

    size_t capacity() const {
        return _capacity;
    }

    void clear() {
        _size = 0;
    }

    bool empty() const {
        return _size == 0;
    }

    char *c_str() const {
        return _data;
    }

    char *&data() {
        return _data;
    }

    char *data() const {
        return _data;
    }

private:
    char *_data;
    size_t _size;
    size_t _capacity;
};

std::ostream &operator<<(std::ostream &os, const string &s) {
    return os << s.c_str();
}

#endif //LEARN_CPP_STRING_TEST_H
