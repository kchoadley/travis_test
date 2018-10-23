### This sets up Build and Test Environment
apt-get -qq -d update
apt-get install -qq -y software-properties-common
add-apt-repository -y ppa:ubuntu-toolchain-r/test
apt-get -qq -d update
# install tools
apt-get -qq -y install cmake cppcheck g++-6 libcpprest-dev libspdlog-dev software-properties-common wget
# make g++ 6 the default g++ executable
update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90
# Google Fruit dependency injection, build install remove old files
mkdir gfruit
cd gfruit
wget https://github.com/google/fruit/archive/v3.4.0.tar.gz
tar -xvzf v3.4.0.tar.gz
cd fruit-3.4.0
cmake -DCMAKE_BUILD_TYPE=Release -DFRUIT_USES_BOOST=False . 
make -j
make install
ldconfig
# gtest libraries, compile, move to lib folder, cleanup
apt-get install libgtest-dev -y -qq 
cd /usr/src/gtest
cmake CMakeLists.txt
make
cp *.a /usr/lib
cd ..
rm -R gtest