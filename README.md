# C++ 面试准备
> 包含经典代码实现，阅读资料以及其他资源的汇总

## 代码实现
### 经典算法
+ [ ] 排序算法
  + [x] [冒泡排序](./algorithm/bubble_sort.cpp)
  + [x] [选择排序](./algorithm/selection_sort.cpp)
  + [x] [插入排序](./algorithm/insertion_sort.cpp)
  + [x] [希尔排序](./algorithm/shell_sort.cpp)
  + [x] [归并排序](./algorithm/merge_sort.cpp)
  + [x] [快速排序](./algorithm/quick_sort.cpp)
  + [ ] 堆排序
  + [ ] 计数排序
  + [ ] 桶排序
  + [ ] 基数排序
+ [ ] 字符串算法
  + [ ] KMP 字符串匹配算法
+ [ ] 二分搜索（找目标值，找左边界，找右边界）
+ [ ] 动态规划
+ [ ] 图算法
  + [ ] 基本遍历
    + [ ] 深度优先搜索
    + [ ] 广度优先搜索
    + [ ] A* 搜索算法
    + [ ] 回溯法
  + [ ] 最短路径算法
    + [ ] Dijkstra 算法
    + [ ] Bellman-Ford 算法
    + [ ] Floyd-Warshall 算法
  + [ ] 最小生成树
    + [ ] Prim 算法
    + [ ] Kruskal 算法
  + [ ] 图匹配
    + [ ] 匈牙利算法

### 数据结构
+ [ ] STL
  + [x] [string](./stl/string.h)
  + [ ] vector
  + [ ] iterator
  + [x] [unordered_map（哈希表）](./stl/unordered_map.h)
  + [ ] map（红黑树）
+ [ ] 并查集
+ [ ] 堆
+ [ ] B 树

### 智能指针
+ [ ] unique_ptr
+ [ ] shared_ptr
+ [ ] weak_ptr

### 网络编程
+ [x] [select](./socket/select.cpp)
+ [x] [poll](./socket/poll.cpp)
+ [x] [epoll](./socket/epoll.cpp)

### 并发编程
+ [x] [互斥锁](./concurrent/mutex.h)
+ [x] [条件变量](./concurrent/condition_variable.h)
+ [x] 阻塞队列
  + [x] [标准库版本](./concurrent/blocking_queue.h)
  + [x] [POSIX 版本（fixed max size）](./concurrent/posix_blocking_queue.h)
+ [ ] 线程池
  + [ ] 标准库版本
  + [ ] POSIX 版本

### 设计模式
+ [x] 单例
  + [x] [懒汉版](./design_pattern/lazy_singleton.cpp)
  + [x] [饿汉版](./design_pattern/eager_singleton.cpp)

### 其他
+ [ ] 内存池

## 阅读资料
### 经典书籍
+ [ ] 《C++ Primer》
+ [ ] 《Effective C++》
+ [ ] 《More Effective C++》
+ [ ] 《Effective STL》
+ [ ] 《Effective Modern C++》
+ [ ] 《C++ 语言的设计与演化》
+ [ ] 《深度探索 C++ 对象模型》
+ [ ] 《STL 源码剖析》
+ [ ] 《C++ 并发编程实战》
+ [ ] 《C++ 沉思录》
+ [ ] 《C++ 模版元编程》
+ [ ] 《C 专家编程》
+ [ ] 《C 陷阱与缺陷》
+ [ ] 《C 语言接口与实现》

### 在线教程
+ [ ] [现代 C++ 教程：高速上手 C++ 11/14/17/20](https://changkun.de/modern-cpp/)
+ [ ] [OI Wiki](https://oi-wiki.org)

## 参考
+ [C++ 实现十大排序算法](https://www.cnblogs.com/BobHuang/p/11263183.html)
+ [图算法领域 10 大经典算法](https://www.cnblogs.com/v-july-v/archive/2011/02/14/1983678.html)
+ [C++ 单例模式](https://zhuanlan.zhihu.com/p/37469260)