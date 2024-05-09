cmake_minimum_required(VERSION 3.28)
project(HuffmanCompression)

set(CMAKE_CXX_STANDARD 17)

add_executable(HuffmanCompression main.cpp
        Huffman.h
        HeapVect.cpp
        HeapVect.h)
