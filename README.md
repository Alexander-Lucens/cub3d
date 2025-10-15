# Cub3D Docker Environment for macOS

---

## ⚙️ One-Time Setup

### 1. Install XQuartz

Download and install:
👉 [https://www.xquartz.org/](https://www.xquartz.org/)

After installation, **log out and back in** (or restart your Mac) so that XQuartz is fully registered in the system.

---

### 2. Configure XQuartz

1. Open **XQuartz**.
2. Go to **XQuartz → Settings → Security**.
3. Enable:

   * ☑ **Allow connections from network clients**

4. Go to **XQuartz → Settings → Input**.
5. Enable:
   * ☑ **Follow system keyboard layout**
   * ☑ **Enable key equivalents under X11**

Then close and reopen XQuartz.

---

### 3. Build the Docker Image

Run once to create the development container:

```bash
docker-compose build
```

---

## 🚀 Daily Workflow

Each time you work on the project, follow these steps.

### 1. Start and Enter the Environment

Simply run:

```bash
./run.sh
```

This script will:

* Detect your Mac’s IP
* Grant XQuartz display access
* Start or rebuild the Docker container
* Compile your project automatically
* Open an interactive shell in the container

You’ll see output like:

```
✅ Mac IP: 192.168.1.42
🔐 Granting display access...
🖥️  DISPLAY set to 192.168.1.42:0
🚀 Building and starting container...
```

Once inside, you can run your program as usual:

```bash
cd cub3d
./so_long maps/map2.ber
```

---

### 2. Exit and Stop

When you’re done:

Exit the container shell:

```bash
exit
```

Then stop the container:

```bash
docker-compose down
```

---