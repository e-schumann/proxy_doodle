cmake_minimum_required (VERSION 3.2)

project(proxy_doodle C CXX)

set (CMAKE_CXX_STANDARD 11)
set( PROJECT_TEST_NAME ${PROJECT_NAME}_test CACHE INTERNAL "${PROJECT_NAME}: Test project name" FORCE )

# Download and unpack googletest at configure time
# https://crascit.com/2015/07/25/cmake-gtest/
#configure_file(extern_boost.in extern/extern-boost/CMakeLists.txt)
#configure_file(CMakeLists.txt.in extern/extern-download/CMakeLists.txt)

#execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/extern/extern-download )
#execute_process(COMMAND ${CMAKE_COMMAND} --build . WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/extern/extern-download )

set (EXECUTE_COMMAND_BOOTSTRAP ./bootstrap.sh )
execute_process( COMMAND ${EXECUTE_COMMAND_BOOTSTRAP} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/external/boost)

set (EXECUTE_COMMAND_B2 ./b2 -j4 --build-dir=./build --prefix=${CMAKE_BINARY_DIR}/boost toolset=gcc cxxflags="-std=c++11" define=BOOST_SYSTEM_NO_DEPRECATED variant=release link=shared threading=multi runtime-link=shared install )

execute_process( COMMAND ${EXECUTE_COMMAND_B2} WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/external/boost )

set( BOOST_INCLUDEDIR ${CMAKE_BINARY_DIR}/boost/include CACHE INTERNAL "Boost include hint" FORCE )
#set( BOOST_LIBRARYDIR ${CMAKE_BINARY_DIR}/boost/lib CACHE INTERNAL "Boost library hint" FORCE )

# when building with Visual Studio

enable_testing()

include(externals.in)



# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main

#add_subdirectory(${CMAKE_BINARY_DIR}/extern/googletest-src ${CMAKE_BINARY_DIR}/extern/googletest-build)
#add_subdirectory(${CMAKE_BINARY_DIR}/extern/extern-boost/)

add_subdirectory(src/util)
add_subdirectory(src/test)


add_test( NAME SingletonTests COMMAND ${PROJECT_TEST_NAME} )

