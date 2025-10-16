# Cub3D Docker Environment for macOS

---

## ⚙️ One-Time Setup

### 1. Install tigervnc-viewer

Download and install:

```sh
brew install tigervnc-viewer
```

---

## 🚀 Daily Workflow

---

Each time you work on the project, follow these steps.

---

### 1. Open Docker Desktop

### 2. Run in terminal script

Builds and run container.

```sh
./run.sh
```

### 3. Configure tigervnc-viewer

1. Open **tigerVNC Viewer**.
2. Fill **VNC server:** with **localhost:5900**
3. Press **Connect** button.

![TigerVNC Viewer Connection](/vnc.png)

**Ist will open screen with debian.**

![TigerVNC Viewer Connection](/vnc-open.png)

---

#### In the end you could stop the container:

```bash
docker compose down
```
---
