FROM debian:buster

ENV DEBIAN_FRONTEND=noninteractive

RUN echo "deb http://archive.debian.org/debian/ buster main" > /etc/apt/sources.list && \
    echo "deb http://archive.debian.org/debian-security buster/updates main" >> /etc/apt/sources.list

RUN apt-get update && apt-get install -y \
    build-essential \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    zlib1g-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/42paris/minilibx-linux.git /usr/local/src/minilibx
RUN cd /usr/local/src/minilibx && make

RUN cp /usr/local/src/minilibx/mlx.h /usr/local/include/
RUN cp /usr/local/src/minilibx/libmlx.a /usr/local/lib/

RUN useradd -m -u 1000 -s /bin/bash student
WORKDIR /home/student/project
USER student

CMD ["bash"]
