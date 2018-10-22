# CPP Build and Test Environment Configuration
To run locally
```
docker build --rm -t cpp-hello-world:test-1 .
```

# Docker Cleanup
Run this to remove all images without a tag
```
docker rmi $(docker images | grep '^<none>')
```
Run this to remove all images with a `test` tag
```
docker rmi $(docker images --format '{{.Repository}}:{{.Tag}}' | grep ':test')
```