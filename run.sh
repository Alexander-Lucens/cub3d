#!/bin/bash

# 1. Find the Mac's IP address on the local network
echo "🔍 Discovering your Mac's IP address..."
# A more robust method to filter out irrelevant addresses
MAC_IP=$(ifconfig | grep 'inet ' | grep -v '127.0.0.1' | awk '{print $2}' | head -n 1)

# Verify if an IP was found
if [ -z "$MAC_IP" ]; then
    echo -e "\033[0;31m❌ Error: Could not determine IP address. Make sure you are connected to a network (Wi-Fi/Ethernet).\033[0m"
    exit 1
fi
echo -e "✅ IP address found: \033[0;32m$MAC_IP\033[0m"

# 2. Grant XQuartz access for this IP
echo "🔐 Granting display access for $MAC_IP..."
xhost + "$MAC_IP"

# 3. Completely restart the container to apply settings
echo "🔄 Restarting Docker container..."
# Hide the output of 'down' to keep the log clean
docker-compose down > /dev/null 2>&1
docker-compose up -d

# 4. Compile the project inside the container, hiding the output
echo -e "\033[42mCompiling project inside the container...\033[0m"
# Added 'make clean' for reliability
docker-compose exec dev bash -c "cd cub3d && make clean > /dev/null 2>&1 && make > /dev/null 2>&1"

# 5. Enter an interactive session
echo -e "\033[42mEntering container shell.\033[0m"
echo -e "\033[42mRun your program now (e.g., ./so_long maps/map2.ber)\033[0m"
docker-compose exec dev bash