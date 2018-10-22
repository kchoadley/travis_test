### This creates the base file for the Build and Test Environment

# Get the base Ubuntu image from Docker Hub
FROM ubuntu:18.04

# Update apps on the base image
RUN apt-get update

RUN apt-get install -y software-properties-common

# add ubuntu toolchain repository and g++
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test
RUN apt-get -qq -d update

# GCC
RUN apt-get -qq -y install g++-6

# make g++ 6 the default g++ executable
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90

# CMake
RUN apt-get install -y cmake

# gtest libraries and compile them
RUN apt-get install libgtest-dev -y -qq

RUN cd /usr/src/gtest \
    cmake CMakeLists.txt \
    make \
    cp *.a /usr/lib

# clean
RUN  apt-get clean

### concludes base image
