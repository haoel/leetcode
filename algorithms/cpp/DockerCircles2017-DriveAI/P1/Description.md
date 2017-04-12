Docker Build Dependencies
=========================

 (Lei Wang, yiak.wy@gmail.com RECALL the problem and made his own version, ALL RIGHTS RESERVED!)

Engineers use docker to build environment. It is a little bit like using Virutal Machine \(Virtual Box from Oracle, or VMware\). 
Fetch the docker image from repository, you can build software directly upon it. e.g:

> if an engineer A insall python in a docker image or server, say Master, another engineer B can use python directly and install other dependencies like py-test.

People can also publish images B from existing image A. For example:

> we already have image Master, we can build another image Ubuntu \(ip: 0.0.10.1\) and install django inside it. Now, docker image Ubuntu 10.1 is now available for retrieving. You can hereby develop a new image upon it.

## Taks Specification

Engineers want to install a new software, which may depend on a series of Docker images. This may frequently happen anywhere in Docker World! Docker build system should execute an routine to update whole system's patches, which subject to the following easy understood conditions:

1. each docker image should have dependency upon another docker image; we call it is the parent of the docker image. In this game, it is unique.
2. a patch cannot be added into the current image only after its parent finish updating.
3. if a series of docker images has a circle, we cannot build patches upon them; we need to discard them temporally.

Given a sequence of docker dependences:

```c++
// <img1, parent1> , <img2, parent2> , ...
vector<pair<string, string>> Relation
```

Try to give a build order by solving the following function

```c++
shared_ptr<vector<string>> BuildDocker(vector<pair<string, string>>)
```

You can specify additional structures, classes or helper functions. The codes should be finished in C++14.

Give your answer within at most 1 hour!

Here is a solution from yiak \(yaik.wy@gmail.com\), for more information please refer to course "Graphics and Basic Tree Operations"

![demo1](https://github.com/yiakwy/Onsite-Blackboard-Code-Interview/raw/master/DockerCircles2017-DriveAI/P1/images/demo1.png)
![demo2](https://github.com/yiakwy/Onsite-Blackboard-Code-Interview/raw/master/DockerCircles2017-DriveAI/P1/images/demo2.png)
