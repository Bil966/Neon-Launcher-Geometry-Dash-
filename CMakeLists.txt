cmake_minimum_required(VERSION 3.15)

project(NeonLauncher)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================
# Auto Get Source Files
# =========================

file(GLOB_RECURSE SOURCE_FILES

    src/*.cpp
    libs/imgui/*.cpp
)

# =========================
# Executable
# =========================

add_executable(NeonLauncher
    ${SOURCE_FILES}
)

# =========================
# Include Directories
# =========================

target_include_directories(NeonLauncher PRIVATE

    src
    include
    libs/imgui
    libs/glfw/include
)

# =========================
# Library Directories
# =========================

target_link_directories(NeonLauncher PRIVATE

    libs/glfw/lib-vc2022
)

# =========================
# Link Libraries
# =========================

target_link_libraries(NeonLauncher PRIVATE

    glfw3
    opengl32
)

# =========================
# Windows Definitions
# =========================

if (WIN32)

    target_compile_definitions(NeonLauncher PRIVATE

        _CRT_SECURE_NO_WARNINGS
    )

endif()