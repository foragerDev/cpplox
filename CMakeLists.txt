cmake_minimum_required(VERSION 3.16)
project(Cpplox VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
set(SOURCES
    source/Lox.cpp
    source/Scanner.cpp
    source/Token.cpp
)
add_executable(Cpplox main.cpp ${SOURCES})
target_include_directories(Cpplox PUBLIC include)
