cmake_minimum_required (VERSION 3.2)

project( proxy C CXX )

find_package( Boost 1.62.0 REQUIRED )

file( GLOB PROXY_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )

include_directories( ${proxy_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/cpp ${CMAKE_CURRENT_SOURCE_DIR}/header)
include_directories( ${Boost_INCLUDE_DIRS} )
#link_directories( ${Boost_LIBRARY_DIRS} )

add_library( ${PROJECT_NAME} SHARED ${PROXY_SRC_FILES} )
target_link_libraries( ${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})



