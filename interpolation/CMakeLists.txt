cmake_minimum_required(VERSION 3.6)
project(interpolation)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp logrange.cpp logrange.h aitken.h)
add_executable(interpolation ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} GL GLU X11 glut )