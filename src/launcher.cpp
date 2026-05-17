#include "launcher.hpp"
#include <windows.h>
#include <fstream>
#include <direct.h>   // _mkdir
#include "json.hpp"

using json = nlohmann::json;

namespace launcher {

    // =========================
    // CHECK FILE EXISTS
    // =========================
    bool fileExists(const std::string& path) {
        DWORD attr = GetFileAttributesA(path.c_str());
        return (attr != INVALID_FILE_ATTRIBUTES);
    }

    // =========================
    // FIND GEOMETRY DASH
    // =========================
    std::string findGeometryDash() {

        std::string paths[] = {
            "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Geometry Dash\\GeometryDash.exe",
            "C:\\Program Files\\Steam\\steamapps\\common\\Geometry Dash\\GeometryDash.exe",
            "D:\\SteamLibrary\\steamapps\\common\\Geometry Dash\\GeometryDash.exe"
        };

        for (auto& p : paths) {
            if (fileExists(p)) {
                return p;
            }
        }

        return "";
    }

    // =========================
    // LAUNCH GAME
    // =========================
    bool launchGame(const std::string& path) {

        HINSTANCE result = ShellExecuteA(
            NULL,
            "open",
            path.c_str(),
            NULL,
            NULL,
            SW_SHOW
        );

        return (int)result > 32;
    }

    // =========================
    // CREATE CONFIG FOLDER
    // =========================
    void ensureConfigFolder() {
        _mkdir("config"); // nếu đã tồn tại cũng không sao
    }

    // =========================
    // SAVE CONFIG (JSON)
    // =========================
    void savePath(const std::string& path) {

        ensureConfigFolder();

        json j;
        j["geometry_dash_path"] = path;

        std::ofstream file("config/config.json");

        if (file.is_open()) {
            file << j.dump(4);
            file.close();
        }
    }

    // =========================
    // LOAD CONFIG (JSON)
    // =========================
    std::string loadSavedPath() {

        std::ifstream file("config/config.json");

        if (!file.is_open()) {
            return "";
        }

        json j;

        try {
            file >> j;
        }
        catch (...) {
            return "";
        }

        if (j.contains("geometry_dash_path")) {
            return j["geometry_dash_path"];
        }

        return "";
    }

}