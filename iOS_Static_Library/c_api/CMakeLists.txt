add_library(c_api_deps STATIC deps/impl.cpp deps/impl2.cpp deps/dummy_impl.cpp)
target_include_directories(c_api_deps PRIVATE 
                           ${CMAKE_CURRENT_SOURCE_DIR}
                           )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections")

add_library(api OBJECT api.cpp)
target_link_libraries(api PRIVATE c_api_deps)
target_include_directories(api PRIVATE 
                           ${CMAKE_CURRENT_SOURCE_DIR}) 

add_custom_target(taichi_c_api)
add_custom_command(
    TARGET taichi_c_api
    COMMAND ld 
    ARGS -exported_symbols_list /tmp/export_symbols_mac.lds -r $<TARGET_OBJECTS:api> $<TARGET_FILE:c_api_deps> -o ${CMAKE_BINARY_DIR}/libtaichi_c_api.a -x -S
    VERBATIM)
add_dependencies(taichi_c_api api c_api_deps)
