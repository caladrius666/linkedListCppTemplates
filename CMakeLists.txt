cmake_minimum_required(VERSION 3.5)
project(templates)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES1 list.cpp list.hpp)
add_executable(list ${SOURCE_FILES1})
set(SOURCE_FILES2 list2.cpp list2.hpp)
add_executable(list2 ${SOURCE_FILES2})
