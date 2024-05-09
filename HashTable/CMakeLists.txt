cmake_minimum_required(VERSION 3.28)
project(HashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable main.cpp
        hashtableTemp.cpp
        hashtable.cpp
        hashtableTemp.cpp)
