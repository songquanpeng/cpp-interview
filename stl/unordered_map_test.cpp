//
// Created by song on 2022/9/28.
//

#include "unordered_map.h"
#include <iostream>

int main() {
    unordered_map<std::string, int> mp;
    std::string s = "s";
    mp[s] = 1;
    std::cout << mp[s] << std::endl;
    mp.erase(s);
    std::cout << mp[s] << std::endl;
    mp.erase(s);
    for (int i = 0; i < 16; i++) {
        auto key = std::to_string(i);
        mp[key] = i;
    }
    std::cout << "size: " << mp.size() << " bucket size: " << mp.bucket_size() << std::endl;
    std::cout << "count: " << count << std::endl;
    for (int i = 0; i < 16; i++) {
        auto key = std::to_string(i);
        mp[key] = 16 - i;
    }
    std::cout << "size: " << mp.size() << " bucket size: " << mp.bucket_size() << std::endl;
    std::cout << "count: " << count << std::endl;
    for (int i = 0; i < 16; i++) {
        auto key = std::to_string(i);
        mp.erase(key);
    }
    std::cout << "size: " << mp.size() << " bucket size: " << mp.bucket_size() << std::endl;
    std::cout << "count: " << count << std::endl;
}