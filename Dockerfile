FROM python

# Avoid prompts from apt
ENV DEBIAN_FRONTEND=noninteractive

# Install essential packages

RUN apt-get update && apt-get install -y \
    g++ \
    make \
    cmake \
    lcov \
    mpich \
    libmpich-dev \
    nlohmann-json3-dev \
    ffmpeg \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install matplotlib numpy

RUN cd /lib && \
    git clone https://github.com/lava/matplotlib-cpp.git

# Set up a working directory
WORKDIR /workspace

# Set the default command to bash
CMD ["/bin/bash"]