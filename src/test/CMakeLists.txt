enable_testing()
set( PROJECT_TEST_NAME ${PROJECT_NAME}_test )

include_directories( ${GTEST_INCLUDE_DIRS} )

file( GLOB UNIT_TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )

add_executable( ${PROJECT_TEST_NAME} ${UNIT_TEST_SRC_FILES} )
add_dependencies( ${PROJECT_TEST_NAME} googletest util )

target_link_libraries( ${PROJECT_TEST_NAME} ${GTEST_LIBS_DIR}/libgtest.a ${GTEST_LIBS_DIR}/libgtest_main.a )
target_link_libraries( ${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT} )

add_test( test1 ${PROJECT_TEST_NAME} )