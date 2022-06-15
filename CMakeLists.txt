cmake_minimum_required(VERSION 3.21)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(dfs dfs.cpp)
add_executable(bfs bfs.cpp)
add_executable(prims prims.cpp)
add_executable(kruskals kruskals.cpp)
