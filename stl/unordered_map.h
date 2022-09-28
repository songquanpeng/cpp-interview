//
// Created by song on 2022/9/28.
// Reference: https://en.cppreference.com/w/cpp/container/unordered_map
//

#ifndef LEARN_CPP_UNORDERED_MAP_H
#define LEARN_CPP_UNORDERED_MAP_H

#include <functional>
#include <vector>
#include <memory>
#include <iostream>

// for debug use only
static int count = 0;

template<typename TKey, typename TValue>
class unordered_map {
private:
    struct Node {
        explicit Node(TKey _key) : key(_key), value(), next(nullptr) {
            count++;
        };

        ~Node() {
            count--;
        }

        TKey key;
        TValue value;
        std::shared_ptr<Node> next;
    };

public:
    unordered_map() : _size(0), _bucket_size(8), _data(_bucket_size), _rehashing(false) {}

    ~unordered_map() = default;

    TValue &operator[](const TKey &key) {
        checkSize();
        auto idx = getIdx(key);
        auto head = _data[idx];
        if (!head) {
            _data[idx] = std::make_shared<Node>(key);
            _size++;
            return _data[idx]->value;
        }
        auto cur = head;
        while (cur) {
            if (cur->key == key) {
                return cur->value;
            }
            if (cur->next) {
                cur = cur->next;
            } else {
                break;
            }
        }
        cur->next = std::make_shared<Node>(key);
        _size++;
        return cur->next->value;
    }

    size_t erase(const TKey &key) {
        checkSize();
        auto idx = getIdx(key);
        auto head = _data[idx];
        if (!head) {
            return 0;
        }
        auto cur = head;
        if (cur->key == key) {
            _data[idx] = cur->next;
            _size--;
            return 1;
        }
        auto prev = cur;
        cur = cur->next;
        while (cur) {
            if (cur->key == key) {
                prev->next = cur->next;
                _size--;
                return 1;
            }
            prev = cur;
            cur = cur->next;
        }
        return 0;
    }

    size_t size() const {
        return _size;
    }

    size_t bucket_size() const {
        return _bucket_size;
    }

private:
    void checkSize() {
        if (_rehashing) return;
        if (_size >= _bucket_size) {
            rehash(_bucket_size * 2);
        }
        // _bucket_size > 8: otherwise, the first insert operation will cause rehashing!
        if (_size < _bucket_size / 2 && _bucket_size > 8) {
            rehash(_bucket_size / 2);
        }
    }

    void rehash(size_t new_bucket_size) {
        _rehashing = true;
        std::vector<std::shared_ptr<Node>> tmp_data(new_bucket_size);
        _data.swap(tmp_data);
        _bucket_size = new_bucket_size;
        _size = 0;
        for (auto node: tmp_data) {
            while (node) {
                operator[](node->key) = node->value;
                node = node->next;
            }
        }
        _rehashing = false;
    }

    size_t getIdx(const TKey &key) {
        return hash(key) % _bucket_size;
    }

private:
    size_t _size;
    size_t _bucket_size;
    std::vector<std::shared_ptr<Node>> _data;
    std::hash<TKey> hash;
    bool _rehashing;  // otherwise, rehash() will call itself!
};

#endif //LEARN_CPP_UNORDERED_MAP_H
