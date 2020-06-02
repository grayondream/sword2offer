cmake_minimum_required(VERSION 3.5)
project(main)

include_directories(include)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. SRC_FILES)

set(SOURCE_FILES main.cpp ${SRC_FILES})

add_executable(main ${SOURCE_FILES})