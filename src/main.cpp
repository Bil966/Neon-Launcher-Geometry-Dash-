#include "ui/ui.hpp"
#include "launcher.hpp"
#include "settings.hpp"

#include <Windows.h>
#include <iostream>

#include <GLFW/glfw3.h>
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

int main() {

    // =========================
    // INIT GLFW
    // =========================
    if (!glfwInit()) {
        std::cout << "Failed to init GLFW!\n";
        return -1;
    }

    const char* glsl_version = "#version 130";

    GLFWwindow* window = glfwCreateWindow(
        1280,
        720,
        "Neon Launcher",
        NULL,
        NULL
    );

    if (!window) {
        std::cout << "Failed to create window!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // =========================
    // INIT IMGUI
    // =========================
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // =========================
    // INIT SETTINGS
    // =========================
    settings::load();

    // =========================
    // INIT LAUNCHER
    // =========================
    std::string gdPath = launcher::loadSavedPath();

    if (gdPath.empty()) {
        gdPath = launcher::findGeometryDash();

        if (!gdPath.empty()) {
            launcher::savePath(gdPath);
        }
    }

    std::cout << "Launcher ready!\n";

    // =========================
    // MAIN LOOP
    // =========================
    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ui::render();

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);

        glViewport(0, 0, display_w, display_h);
        glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // =========================
    // SAVE SETTINGS ON EXIT
    // =========================
    settings::save();

    // =========================
    // CLEANUP
    // =========================
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}