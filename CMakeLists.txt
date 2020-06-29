# cmake_minimum_required(VERSION <specify CMake version here>)
project(postfix_eval_andrewwmclain)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(postfix_eval_andrewwmclain
        evaluator.cpp
        evaluator.h
        main.cpp)
