cmake_minimum_required(VERSION 3.0)
project(learn_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(select socket/select.cpp)
add_executable(poll socket/poll.cpp)
add_executable(epoll socket/epoll.cpp)
add_executable(string stl/string.cpp)
add_executable(lazy_singleton design_pattern/lazy_singleton.cpp)
add_executable(eager_singleton design_pattern/eager_singleton.cpp)
add_executable(blocking_queue concurrent/blocking_queue_test.cpp)
add_executable(posix_blocking_queue concurrent/posix_blocking_queue_test.cpp)