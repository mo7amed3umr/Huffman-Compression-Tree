cmake_minimum_required(VERSION 3.10.2)
project(huffman)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(huffman
        apps/compress.cpp
        apps/decompress.cpp
        apps/huffMan.cpp
        apps/run.cpp
        include/fileProcess.h
        include/huffMan.h)
