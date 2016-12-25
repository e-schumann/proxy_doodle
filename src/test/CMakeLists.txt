cmake_minimum_required (VERSION 3.2)

project( unittests C CXX )

#find_package( Boost 1.62.0 REQUIRED filesystem )
find_package( GTest )

file( GLOB UNIT_TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )

if( NOT ${GTest_FOUND} )
   add_custom_target( Rescan ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} DEPENDS ${GOOGLETEST_NAME} )
else()
   add_custom_target( Rescan )
   message( "GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}" )
   message( "GTEST_BOTH_LIBRARIES: ${GTEST_BOTH_LIBRARIES}" )
   include_directories( ${GTEST_INCLUDE_DIRS}/include ${util_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/cpp )
endif()

add_executable( ${PROJECT_TEST_NAME} ${UNIT_TEST_SRC_FILES} )
add_dependencies( ${PROJECT_TEST_NAME} Rescan )

#if( ${GTest_FOUND} )
   message( "GTEST_BOTH_LIBRARIES: ${GTEST_BOTH_LIBRARIES}" )
   target_link_libraries( ${PROJECT_TEST_NAME} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
#endif()


