add_executable(mcweb3_vulkan_test bgfx_init_test.cpp)
target_link_libraries(mcweb3_vulkan_test bgfx bimg bx)
target_include_directories(mcweb3_vulkan_test PRIVATE
    ${CMAKE_SOURCE_DIR}/thirdparty/bgfx.cmake/bgfx/include
    ${CMAKE_SOURCE_DIR}/thirdparty/bgfx.cmake/bx/include
)
