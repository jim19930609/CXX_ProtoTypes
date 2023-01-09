cmake_minimum_required(VERSION 3.17)

project(ios_static)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(c_api)

add_executable(main main.cpp)
target_link_libraries(main ${CMAKE_BINARY_DIR}/libtaichi_c_api.a)

add_dependencies(main taichi_c_api)
