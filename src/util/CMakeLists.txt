# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

file( GLOB UTIL_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/header/*.h )

add_library( library_iface INTERFACE )
target_compile_definitions( library_iface INTERFACE LIBRARY_HEADER_ONLY )

#set(installed_srcs ${UTIL_SRC_FILES} )
#add_library(library_srcs INTERFACE)
#target_sources(library_srcs INTERFACE $<INSTALL_INTERFACE:${installed_srcs}>


install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/export DESTINATION include/ )
install(FILES ${UTIL_SRC_FILES} DESTINATION include/ )
install(TARGETS library_static library_shared library_iface library_srcs EXPORT library_targets
  RUNTIME DESTINATION bin ARCHIVE DESTINATION lib LIBRARY DESTINATION lib INCLUDES DESTINATION include )
install(EXPORT library_targets NAMESPACE example_lib:: DESTINATION lib/cmake/example_lib )

install(FILES example_lib-config.cmake DESTINATION lib/cmake/example_lib )
