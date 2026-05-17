# 🚀 Neon Launcher

A lightweight Geometry Dash launcher + mod utility tool built with C++ (ImGui + GLFW).

---

## 📌 Overview

Neon Launcher is a custom desktop tool designed to:

- Launch Geometry Dash easily
- Detect game installation path automatically
- Manage settings (noclip, speedhack, etc.)
- Install / manage Geode framework
- Provide a clean ImGui-based UI

---

## ✨ Features

### 🎮 Game Launcher
- Auto-detect Geometry Dash installation
- Manual launch support
- Save last detected path

### ⚙ Settings System
- Save / load configuration via JSON
- Persistent mod states:
  - Noclip toggle
  - Speedhack toggle
  - Speed multiplier

### 📦 Geode Integration
- Install Geode framework
- Detect installation status
- Progress bar for downloads

### 🎨 UI
- Built with ImGui
- Tab-based interface:
  - Home
  - Game
  - Mods
  - Settings

---

## 🧠 Tech Stack

- C++
- GLFW
- OpenGL
- Dear ImGui
- JSON (nlohmann)

---

## 📁 Project Structure
src/
├── main.cpp
├── ui/
├── launcher/
├── settings.cpp / .hpp

config/
└── settings.json


---

## ⚙ Build Instructions

### Requirements:
- CMake
- Visual Studio (MSVC)
- GLFW
- OpenGL
- ImGui

### Build:

```bash
cmake -S . -B build
cmake --build build  '''
---
### 🚀 Usage
1. Run the launcher
2. Select Geometry Dash path (auto-detected if available)
3.Use tabs:
Game → launch GD
Mods → toggle features
Settings → save config
Install Geode if needed

📌 Notes

Settings are stored in:
''' bash 
config/settings.json '''

⚖ License

This project is licensed under:

GNU Affero General Public License v3.0

See LICENSE file for full details.

👤 Author

NeonGD1667

💀 Disclaimer

This project is not affiliated with RobTop Games or Geometry Dash.
Use responsibly.
