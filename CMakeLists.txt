cmake_minimum_required(VERSION 3.29)
project(Labs C)

set(CMAKE_C_STANDARD 23)
set(a "Individual_2")
add_executable(Labs ${a}/main.c
        ${a}/lib.c
        ${a}/lib.h)

