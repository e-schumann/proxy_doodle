cmake_minimum_required (VERSION 3.2)

project( util C CXX )

file( GLOB UTIL_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/header/*.h )

add_library( ${PROJECT_NAME} INTERFACE )
target_include_directories( ${PROJECT_NAME} INTERFACE ... )
target_sources( ${PROJECT_NAME} INTERFACE ${UTIL_SRC_FILES} )

set( ${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/header CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE )