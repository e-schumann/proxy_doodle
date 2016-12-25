#include "boost/filesystem.hpp"

static const boost_part::filesystem::path::codecvt_type &dummy =
  boost_part::filesystem::path::codecvt();

int main()
{
  return 0;
}

