cmake_minimum_required(VERSION 3.6)
project(MMN)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MMN.cpp MMN.h Gays.cpp Gays.h)
add_executable(MMN ${SOURCE_FILES})