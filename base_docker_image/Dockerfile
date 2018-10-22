### This creates the base file for the Build and Test Environment

# Get the base Ubuntu image from Docker Hub
FROM ubuntu:18.04

# add ubuntu toolchain repository
RUN apt-get -qq -d update
RUN apt-get install -qq -y software-properties-common
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN apt-get -qq -d update

# install tools
RUN apt-get -qq -y install \
        cmake \
        g++-6 \
        software-properties-common

# make g++ 6 the default g++ executable
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90

# gtest libraries, compile, move to lib folder, cleanup
RUN apt-get install libgtest-dev -y -qq &&\
    cd /usr/src/gtest &&\
    cmake CMakeLists.txt &&\
    make &&\
    cp *.a /usr/lib &&\
    cd .. &&\
    rm -R gtest

### concludes base image
