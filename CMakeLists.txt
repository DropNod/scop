cmake_minimum_required(VERSION 3.10)

project(scop)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
)

add_executable(scop ${SOURCES})