cmake_minimum_required(VERSION 3.0.0)
project(bt_binary_search VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(test_bs
    test_bs.c
    binary_search.c
)

target_compile_options(test_bs PUBLIC -Wall)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
