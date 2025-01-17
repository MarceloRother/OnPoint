#include "MainContext.hpp"

MainContext::MainContext() {}

MainContext::~MainContext() {}

void MainContext::DrawMainContext() {
    DrawMainMenu();
    DrawSideBar();
    DrawMainContent(); 
}

void MainContext::DrawMainMenu() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("New")) { /* Ação */ }
            if (ImGui::MenuItem("Open", "Ctrl+O")) { /* Ação */ }
            if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Ação */ }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Undo", "Ctrl+Z")) { /* Ação */ }
            if (ImGui::MenuItem("Redo", "Ctrl+Y")) { /* Ação */ }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void MainContext::DrawSideBar() {
    ImGui::Begin("Sidebar", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::Text("Options:");
    if (ImGui::Button("Button 1")) { /* Ação */ }
    if (ImGui::Button("Button 2")) { /* Ação */ }
    ImGui::End();
}

void MainContext::DrawMainContent() {
    ImGui::Begin("Main Content");
    ImGui::Text("Welcome to the application!");
    float val = 0;
    ImGui::SliderFloat("Value", &val, 0.0, 1.0);
    ImGui::End();
}
