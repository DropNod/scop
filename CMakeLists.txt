cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(scop)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
)

add_executable(scop ${SOURCES})

find_package(glfw3 3.3 REQUIRED)
find_package(Vulkan REQUIRED)

target_link_libraries(scop glfw Vulkan::Vulkan)