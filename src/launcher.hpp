#pragma once
#include <string>

namespace launcher {

    // ===== CORE =====
    std::string findGeometryDash();   // scan game lần đầu
    bool fileExists(const std::string& path);
    bool launchGame(const std::string& path);

    // ===== CONFIG (JSON) =====
    std::string loadSavedPath();      // đọc config.json
    void savePath(const std::string& path); // lưu config.json

}