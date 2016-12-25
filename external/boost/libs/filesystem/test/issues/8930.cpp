// Before running this test: export LANG=foo

#include <boost/filesystem.hpp>
int main() {
  boost_part::filesystem::path("/abc").root_directory();
}

