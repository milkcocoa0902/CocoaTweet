FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y tzdata && apt-get clean
ENV TZ=Asia/Tokyo
RUN apt-get update && \
apt-get install -y clang \
cmake \
doxygen \
git \
graphviz \
libboost-dev \
libboost-test-dev \
libcurl4-openssl-dev \
libssl-dev \
ninja-build \
pkg-config && \
apt-get clean
