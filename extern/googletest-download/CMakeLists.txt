cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "/home/thor/develop/proxy_doodle/extern/googletest-src"
  BINARY_DIR        "/home/thor/develop/proxy_doodle/extern/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)

ExternalProject_Add(spdlog
  GIT_REPOSITORY    https://github.com/gabime/spdlog.git
  GIT_TAG           master
  SOURCE_DIR        "/home/thor/develop/proxy_doodle/extern/spdlog-src"
  BINARY_DIR        "/home/thor/develop/proxy_doodle/extern/spdlog-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
