#pragma once

#include "../../include/imgui.h"
#include "../../include/backends/imgui_impl_opengl3.h"
#include "../../include/backends/imgui_impl_glfw.h"

class MainContext {
public:
    MainContext();
    ~MainContext();
    void DrawMainContext();

private:
    void DrawMainMenu();
    void DrawSideBar();
    void DrawMainContent();
};
