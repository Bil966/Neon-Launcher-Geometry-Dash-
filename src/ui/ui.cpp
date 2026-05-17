#include "ui/ui.hpp"
#include "settings.hpp"
#include "launcher.hpp"
#include "process.hpp"
#include "imgui.h"
#include <string>

namespace ui {

    void render() {

        static std::string gdPath = launcher::loadSavedPath();
        bool gdRunning = process::isRunning("GeometryDash.exe");

        ImGui::Begin("Neon Launcher", nullptr, ImGuiWindowFlags_NoCollapse);

        // =========================
        // HEADER
        // =========================
        ImGui::TextColored(ImVec4(0.4f, 0.8f, 1.0f, 1.0f), "Neon Launcher");
        ImGui::TextDisabled("Geometry Dash Utility Tool");
        ImGui::Separator();

        // =========================
        // QUICK STATUS
        // =========================
        ImGui::Text("Game Status: ");
        ImGui::SameLine();

        if (gdRunning) {
            ImGui::TextColored(ImVec4(0, 1, 0, 1), "RUNNING");
        } else {
            ImGui::TextColored(ImVec4(1, 0, 0, 1), "NOT RUNNING");
        }

        ImGui::Spacing();

        // =========================
        // TAB SYSTEM
        // =========================
        if (ImGui::BeginTabBar("MainTabs")) {

            // =========================
            // HOME
            // =========================
            if (ImGui::BeginTabItem("Home")) {

                ImGui::TextWrapped("Simple Geometry Dash launcher + utility tool.");

                ImGui::Separator();

                ImGui::BulletText("Noclip: %s", settings::noclip ? "ON" : "OFF");
                ImGui::BulletText("Speedhack: %s", settings::speedhack ? "ON" : "OFF");
                ImGui::BulletText("Speed: %.2f", settings::speed);

                ImGui::EndTabItem();
            }

            // =========================
            // GAME
            // =========================
            if (ImGui::BeginTabItem("Game")) {

                ImGui::Text("Geometry Dash Path:");

                if (gdPath.empty()) {
                    ImGui::TextColored(ImVec4(1, 0, 0, 1), "Not Found");
                } else {
                    ImGui::TextWrapped("%s", gdPath.c_str());
                }

                ImGui::Spacing();

                if (gdRunning) {
                    ImGui::BeginDisabled();
                }

                if (ImGui::Button("Launch Game", ImVec2(200, 35))) {
                    launcher::launchGame(gdPath);
                }

                if (gdRunning) {
                    ImGui::EndDisabled();
                }

                ImGui::EndTabItem();
            }

            // =========================
            // MODS
            // =========================
            if (ImGui::BeginTabItem("Mods")) {

                ImGui::Checkbox("Noclip", &settings::noclip);
                ImGui::Checkbox("Speedhack", &settings::speedhack);

                ImGui::SliderFloat("Speed", &settings::speed, 0.1f, 5.0f);

                ImGui::Spacing();

                if (ImGui::Button("Save Settings", ImVec2(200, 30))) {
                    settings::save();
                }

                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::End();
    }

}