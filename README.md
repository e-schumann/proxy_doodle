Sorry, building takes a while (it includes a full boost distribution ;-) )


Netbeans has nice built in cmake support

Currently only setup for linux/gcc!

gradle naming conventions for directory structure and tests.

1. git clone https://github.com/snikulov/google-test-examples.git
2. cd google-test-examples
3. mkdir build
4. cd build
5. cmake ..
6. cmake --build .       ( cmake --build . -- VERBOSE=1)
7. ctest -VV



git clone --recursive https://github.com/boostorg/boost.git boost-git
cd boost-git
git fetch --all --tags --prune
git checkout tags/boost-1.62.0 -b t_build_1_62   <==== don't! This tagged version of Jamfile is not working (python rule is missing!)
./bootstrap.sh
./b2 -j4 --build-dir=./build --layout=versioned toolset=gcc cxxflags="-std=c++11" variant=release link=shared threading=multi runtime-link=shared
./b2 toolset=gcc cxxflags="-std=c++11" tools/bcp

dist/bin/bcp --boost=/opt/software/boost-git filesystem config build $HOME/develop/proxy_doodle_2/external/boost

Remark: .git are copied to (which result in fatal error when doing git add boost_extract)


http://stackoverflow.com/questions/28182598/how-to-extract-boostfilesystem-using-bcp
https://steveire.wordpress.com/2016/08/21/boost-dependencies-and-bcp/
http://www.boost.org/doc/libs/1_61_0/tools/bcp/doc/html/index.html
http://stackoverflow.com/questions/4831056/create-boost-tool-executable
