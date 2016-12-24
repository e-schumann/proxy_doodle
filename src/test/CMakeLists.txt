cmake_minimum_required (VERSION 3.2)

project( ${PROJECT_TEST_NAME} )

enable_testing()

include_directories( ${gtest_SOURCE_DIR}/include ${util_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/cpp )
link_directories( ${gmock_BINARY_DIR}/gtest )
message( STATUS "gmock_BINARY_DIR: " ${gmock_BINARY_DIR} )


file( GLOB UNIT_TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )

add_executable( ${PROJECT_TEST_NAME} ${UNIT_TEST_SRC_FILES} )
add_dependencies( ${PROJECT_TEST_NAME} gtest gtest_main util )

target_link_libraries( ${PROJECT_TEST_NAME} gtest gtest_main )
target_link_libraries( ${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT} )

add_test( test1 ${PROJECT_TEST_NAME} )