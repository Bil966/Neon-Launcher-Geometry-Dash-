#pragma once
#include <string>

namespace geode {

    // trạng thái download
    extern bool isDownloading;
    extern float progress;

    // install Geode (async)
    void install();

    // check đã cài chưa (basic)
    bool isInstalled(const std::string& gdPath);
}