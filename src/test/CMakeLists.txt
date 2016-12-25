cmake_minimum_required (VERSION 3.2)

#project( ${PROJECT_TEST_NAME} )
project( unittests C CXX )

find_package( Boost 1.62.0 REQUIRED filesystem )
find_package( GTest REQUIRED )

#enable_testing()

include_directories( ${GTEST_INCLUDE_DIRS} ${util_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/cpp )
#link_directories( ${gmock_BINARY_DIR}/gtest )

message( STATUS "google test includes ${GTEST_INCLUDE_DIRS}" )

file( GLOB UNIT_TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )

add_executable( ${PROJECT_TEST_NAME} ${UNIT_TEST_SRC_FILES} )
#add_dependencies( ${PROJECT_TEST_NAME} googletest )
#add_dependencies( ${PROJECT_TEST_NAME} gtest gtest_main util )

target_link_libraries( ${PROJECT_TEST_NAME} ${GTEST_BOTH_LIBRARIES} )
target_link_libraries( ${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT} )

#add_test( test1 ${PROJECT_TEST_NAME} )
