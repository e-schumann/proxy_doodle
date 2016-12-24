file( GLOB UTIL_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/header/*.h )

add_library( util INTERFACE )
target_include_directories( util INTERFACE ... )
target_sources( util INTERFACE ${UTIL_SRC_FILES} )
