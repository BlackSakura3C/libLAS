cmake_minimum_required(VERSION 3.16)
project(untitled)

link_libraries("/usr/local/lib/liblas.so.2.4.0" )
set(CMAKE_CXX_STANDARD 14)
add_executable(untitled main.cpp)

