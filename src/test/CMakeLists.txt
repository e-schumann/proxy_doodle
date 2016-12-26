cmake_minimum_required (VERSION 3.2)

project( unittests C CXX )

#set( Boost_USE_STATIC_LIBS ON)
find_package( Boost 1.62.0 REQUIRED COMPONENTS system filesystem )

find_package( GTest )

file( GLOB UNIT_TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )

#ToDo: Remove this in favor of an execute_process call in the main CMakeLists.txt
if( NOT ${GTest_FOUND} )
   add_custom_target( Rescan ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} DEPENDS ${GOOGLETEST_NAME} )
else()
   add_custom_target( Rescan )
   #message( "GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}" )
   #message( "GTEST_BOTH_LIBRARIES: ${GTEST_BOTH_LIBRARIES}" )
   include_directories( ${GTEST_INCLUDE_DIRS}/include )
endif()

#include_directories( ${util_INCLUDE_DIRS} ${proxy_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/cpp )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/cpp )
include_directories( ${Boost_INCLUDE_DIRS} )
link_directories( ${Boost_LIBRARY_DIRS} ${proxy_LIBRARY_DIRS} )

add_executable( ${PROJECT_TEST_NAME} ${UNIT_TEST_SRC_FILES} )
add_dependencies( ${PROJECT_TEST_NAME} Rescan  )

#if( ${GTest_FOUND} )
#message( "GTEST_BOTH_LIBRARIES: ${GTEST_BOTH_LIBRARIES}" )
target_link_libraries( ${PROJECT_TEST_NAME} proxy util ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
#endif()


