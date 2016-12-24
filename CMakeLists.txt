cmake_minimum_required (VERSION 3.2)

project(proxy_doodle C CXX)

set (CMAKE_CXX_STANDARD 11)
set( PROJECT_TEST_NAME ${PROJECT_NAME}_test CACHE INTERNAL "${PROJECT_NAME}: Test project name" FORCE )

# Download and unpack googletest at configure time
# https://crascit.com/2015/07/25/cmake-gtest/
configure_file(CMakeLists.txt.in extern/extern-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/extern/extern-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/extern/extern-download )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/extern/googletest-src ${CMAKE_BINARY_DIR}/extern/googletest-build)


add_subdirectory(src/util)
add_subdirectory(src/test)

enable_testing()

add_test( NAME SingletonTests COMMAND ${PROJECT_TEST_NAME} )

