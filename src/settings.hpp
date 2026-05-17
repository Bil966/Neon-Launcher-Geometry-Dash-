#pragma once

namespace settings {

    extern bool noclip;
    extern bool speedhack;
    extern float speed;
    extern bool autoLaunch;

    void load();
    void save();

}