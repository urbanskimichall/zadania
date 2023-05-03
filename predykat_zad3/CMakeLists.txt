cmake_minimum_required(VERSION 3.15)
project(predykat_zad3)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Google_test)

add_executable(predykat_zad3 main.cpp function.h)