FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Update package list and install C development tools
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    gdb \
    make \
    cmake \
    valgrind \
    git \
    vim \
    nano \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

CMD ["/bin/bash"]