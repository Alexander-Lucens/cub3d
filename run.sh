#!/bin/bash

set -e

echo "🔍 Detecting environment..."
OS=$(uname -s)

# -----------------------------
# 1. macOS: find IP and check XQuartz
# -----------------------------
if [[ "$OS" == "Darwin" ]]; then
  echo "🧠 macOS detected."

  # Find the IP address of the Mac
  MAC_IP=$(ipconfig getifaddr en0 2>/dev/null || ipconfig getifaddr en1 2>/dev/null)
  if [ -z "$MAC_IP" ]; then
    echo -e "\033[0;31m❌ Could not determine your IP address (Wi-Fi/Ethernet not found).\033[0m"
    exit 1
  fi
  echo -e "✅ Mac IP: \033[0;32m$MAC_IP\033[0m"

  # Check if XQuartz is running
  if ! pgrep -x "XQuartz" >/dev/null; then
    echo -e "\033[0;33m⚠️  XQuartz is not running. Starting it now...\033[0m"
    open -a XQuartz
    sleep 2
  fi

  # Enable network clients
  echo "🔐 Granting display access..."
  xhost + "$MAC_IP" >/dev/null 2>&1 || true
  xhost +localhost >/dev/null 2>&1 || true

  # Set DISPLAY for Docker
  export DISPLAY="$MAC_IP:0"
  echo "🖥️  DISPLAY set to $DISPLAY"
else
  echo "🐧 Linux detected."
  export DISPLAY=${DISPLAY:-:0}
fi

# -----------------------------
# 2. Update docker-compose.yml on the fly (optional)
# -----------------------------
# This step injects DISPLAY dynamically to avoid hardcoding IP in yaml
if ! grep -q "$DISPLAY" docker-compose.yml; then
  echo "🧩 Updating DISPLAY inside docker-compose.yml..."
  sed -i.bak "s|DISPLAY=.*|DISPLAY=$DISPLAY|g" docker-compose.yml 2>/dev/null || true
fi

# -----------------------------
# 3. Start / rebuild container
# -----------------------------
echo "🚀 Building and starting container..."
docker-compose up -d --build

# -----------------------------
# 4. Build project inside container
# -----------------------------
echo -e "\033[42mCompiling project inside the container...\033[0m"
docker-compose exec dev bash -c "
  cd cub3d && make clean > /dev/null 2>&1 && make -s || exit 1
"

# -----------------------------
# 5. Open interactive shell
# -----------------------------
echo -e "\033[42mEntering container shell.\033[0m"
echo -e "\033[42mRun your program (e.g. ./so_long maps/map2.ber)\033[0m"
docker-compose exec dev bash
