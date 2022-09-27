//
// Created by song on 2022/9/27.
//

#include "blocking_queue.h"
#include <iostream>

using namespace std;

int main() {
    BlockingQueue<int> queue;
    queue.push(1);
    queue.push(2);
    int data;
    queue.pop(data);
    cout << data << endl;
    cout << queue.popWithTimeout(data, 1) << " " << data << endl;
    cout << queue.popWithTimeout(data, 1) << " " << data << endl;
}