cmake_minimum_required(VERSION 3.17)

project(ios_static)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)

add_library(c_api_deps STATIC deps/impl.cpp deps/impl2.cpp deps/dummy_impl.cpp)
target_include_directories(c_api_deps PRIVATE ${CMAKE_SOURCE_DIR})


add_library(api OBJECT api.cpp)
target_link_libraries(api PRIVATE c_api_deps)
target_include_directories(api PRIVATE ${CMAKE_SOURCE_DIR})

add_custom_target(dummy_target ALL)
add_custom_command(
    TARGET dummy_target
    COMMAND ld 
    ARGS -exported_symbols_list /tmp/export_symbols_mac.lds -r $<TARGET_OBJECTS:api> $<TARGET_FILE:c_api_deps> -o libtaichi_c_api.a -x -S
    VERBATIM)
add_dependencies(dummy_target api c_api_deps)

#execute_process(COMMAND ld -exported_symbols_list /tmp/export_symbols_mac.lds -r $<TARGET_FILE:api> $<TARGET_FILE:c_api_deps> -o libtaichi_c_api.a -x -S)
