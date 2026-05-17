#include "geode_manager.hpp"
#include <windows.h>
#include <urlmon.h>
#include <thread>
#include <fstream>

#pragma comment(lib, "urlmon.lib")

namespace geode {

    bool isDownloading = false;
    float progress = 0.0f;

    // =========================
    // DOWNLOAD FILE (no progress real-time limit)
    // =========================
    bool downloadFile(const std::string& url, const std::string& path) {

        return URLDownloadToFileA(
            NULL,
            url.c_str(),
            path.c_str(),
            0,
            NULL
        ) == S_OK;
    }

    // =========================
    // INSTALL GEODE
    // =========================
    void install() {

        std::thread([]() {

            isDownloading = true;
            progress = 0.0f;

            std::string url =
                "https://github.com/geode-sdk/geode/releases/latest/download/geode-installer.exe";

            std::string output = "geode-installer.exe";

            // fake progress start
            progress = 0.2f;

            bool ok = downloadFile(url, output);

            progress = 1.0f;
            isDownloading = false;

            if (ok) {
                ShellExecuteA(NULL, "open", output.c_str(), NULL, NULL, SW_SHOW);
            }

        }).detach();
    }

    // =========================
    // CHECK INSTALLED (basic)
    // =========================
    bool isInstalled(const std::string& gdPath) {

        std::string folder =
            gdPath.substr(0, gdPath.find_last_of("\\/")) + "\\geode";

        DWORD attr = GetFileAttributesA(folder.c_str());

        return (attr != INVALID_FILE_ATTRIBUTES);
    }
}