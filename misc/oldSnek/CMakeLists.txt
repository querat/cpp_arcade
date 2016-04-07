cmake_minimum_required(VERSION 3.4)
project(retry_opengl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp field.hpp snake.hpp Painter.hpp game.hpp Painter.cpp Field.cpp SNake.cpp game.cpp)
add_executable(retry_opengl ${SOURCE_FILES})