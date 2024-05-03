cmake_minimum_required(VERSION 3.28)
project(MathParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(MathParser main.cpp
        MathParser.cpp
        MathParser.h
        Stack.h)
