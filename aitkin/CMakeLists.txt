cmake_minimum_required(VERSION 3.7)
project(aitkin)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp aitkin.cpp aitkin.h)
add_executable(aitkin ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} GL GLU X11 glut )