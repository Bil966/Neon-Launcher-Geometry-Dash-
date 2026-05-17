#include "settings.hpp"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

namespace settings {

    bool noclip = false;
    bool speedhack = false;
    float speed = 1.0f;
    bool autoLaunch = false;

    void load() {

        std::ifstream file("config/settings.json");

        if (!file.is_open()) return;

        json j;

        try {
            file >> j;
        }
        catch (...) {
            return;
        }

        noclip = j.value("noclip", false);
        speedhack = j.value("speedhack", false);
        speed = j.value("speed", 1.0f);
        autoLaunch = j.value("autoLaunch", false);
    }

    void save() {

        json j;

        j["noclip"] = noclip;
        j["speedhack"] = speedhack;
        j["speed"] = speed;
        j["autoLaunch"] = autoLaunch;

        std::ofstream file("config/settings.json");

        if (file.is_open()) {
            file << j.dump(4);
            file.close();
        }
    }

}