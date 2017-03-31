cmake_minimum_required(VERSION 3.6)
project(MHD)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MHD.cpp MHD.h)
add_executable(MHD ${SOURCE_FILES})
target_link_libraries(MHD m)