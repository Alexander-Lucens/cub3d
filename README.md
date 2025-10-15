# Cub3D Docker Environment for macOS

This setup allows you to develop and run the 42 School `cub3d` project in a Linux environment on your Mac, with full graphical support via XQuartz.

---

## 🚀 One-Time Setup

You only need to perform these steps once when you first set up the project.

### 1. Install XQuartz
Download and install the latest version from [https://www.xquartz.org/](https://www.xquartz.org/).

> **Important**: After installation, you **must log out** of your macOS user account and log back in for the system to recognize it. A full reboot also works.

### 2. Configure XQuartz
Launch the XQuartz application. In the menu bar, navigate to `XQuartz > Settings... > Security` and ensure that **"Allow connections from network clients"** is checked.



### 3. Build the Docker Image
This command builds the container environment specified in the `Dockerfile`. It only needs to be run again if you modify the `Dockerfile` itself.

```bash
docker-compose build
```

## 🖥️ Daily Workflow

Follow these steps each time you want to work on the project.

### Run the Project
The run.sh script automates everything: it grants display permissions, starts the container, compiles your code, and drops you into the container's command line.

```bash
./run.sh
```

The script will handle the display permissions automatically. You should see output similar to this when it runs:

```bash
✅ IP address found: 192.168.1.123
🔐 Granting display access for 192.168.1.123...
192.168.1.123 being added to access control list
```

### Stop the Environment

When you are finished working, follow these two steps to exit cleanly.

First, exit the interactive shell inside the container:

```bash
exit
```

Then, shut down the container to free up system resources:

```bash
docker-compose down
```

