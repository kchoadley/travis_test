# Get the base Ubuntu image from Docker Hub
FROM kchoadley/exercism-cpp-test-env

# Set the folder name to be the same as the lesson name
ARG DIR=hello-world

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . "/usr/src/${DIR}"

# Specify the working DIRectory
WORKDIR "/usr/src/${DIR}"

RUN mkdir build
WORKDIR "/usr/src/${DIR}/build"

RUN cmake -G "Unix Makefiles" ..
RUN make
