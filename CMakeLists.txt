cmake_minimum_required(VERSION 3.1)
project(yahtzee)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(yahtzee main.cpp main.hpp)
