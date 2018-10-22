# Travis Test - Build and Test Environment Base Image Docker File

If the base image needs to be adjusted, this is the Dockerfile that generates it.

Build simply with 

```
docker build -t cpp-test-env:my-tag .
```

to push image to DockerHub

```
$ docker tag image-name:tag {docker-hub-username}/{default-repo-folder-name}:tag

$ docker push {docker-hub-username}/{default-repo-folder-name}:first-image
```

For example, if I have an image called `cpp-test-env:gtest`

```
$ docker tag cpp-test-env:gtest kchoadley/cpp-test-env:gtest

$ docker push kchoadley/cpp-test-env:gtest
```