# ...existing code...
FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    zlib1g-dev \
    git \
    xvfb \
    x11vnc \
    fluxbox \
    && rm -rf /var/lib/apt/lists/*

# MiniLibX
RUN git clone https://github.com/42Paris/minilibx-linux.git /usr/local/src/minilibx && \
    make -C /usr/local/src/minilibx && \
    cp /usr/local/src/minilibx/mlx.h /usr/local/include/ && \
    cp /usr/local/src/minilibx/libmlx.a /usr/local/lib/

# Ensure X socket directory exists with correct perms (created as root during build)
RUN mkdir -p /tmp/.X11-unix && chmod 1777 /tmp/.X11-unix

# User setup
RUN useradd -m -u 1000 -s /bin/bash student
USER student
WORKDIR /home/student/project

# Launch virtual X + VNC by default
CMD bash -c "Xvfb :0 -screen 0 1280x800x24 >/proc/1/fd/1 2>&1 & \
              sleep 1; \
              fluxbox >/proc/1/fd/1 2>&1 & \
              exec x11vnc -display :0 -nopw -forever -shared -rfbport 5900 -noxdamage -o /proc/1/fd/1"
