#include <filesystem>
#include <iostream>
#include <GLFW/glfw3.h>
#include <ostream>
#include <string>

#include "../include/imgui.h"
#include "../include/backends/imgui_impl_opengl3.h"
#include "../include/backends/imgui_impl_glfw.h"

#include "model/DummyModel.hpp"
#include "controller/DummyController.hpp"
#include "view/DummyView.hpp"
#include "view/MainContext.hpp"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

namespace fs = std::filesystem;

int main() {
   // inicializando a janela do glfw
    if (!glfwInit()) {
        std::cerr << "Could not initialize GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   
    GLFWwindow* window = glfwCreateWindow(WIN_WIDTH,
                                          WIN_HEIGHT, 
                                          "OnPoint: Ponto Eletrônico", 
                                          nullptr, 
                                          nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    // Maximiza janela
    glfwMaximizeWindow(window);

    // inicializando o imgui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    // parte de estilo, o padrao eh muito feio 
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // Fundo da aplicacao
    colors[ImGuiCol_WindowBg]        = ImVec4(0.92f, 0.96f, 0.98f, 1.0f);
    colors[ImGuiCol_ChildBg]         = ImVec4(0.94f, 0.97f, 0.99f, 1.0f); 

    // Texto
    colors[ImGuiCol_Text]            = ImVec4(0.1f, 0.1f, 0.1f, 1.0f);
    colors[ImGuiCol_TextDisabled]    = ImVec4(0.5f, 0.5f, 0.5f, 1.0f);

    // Botoes 
    colors[ImGuiCol_Button]          = ImVec4(0.67f, 0.84f, 0.90f, 1.0f); 
    colors[ImGuiCol_ButtonHovered]   = ImVec4(0.53f, 0.77f, 0.85f, 1.0f);
    colors[ImGuiCol_ButtonActive]    = ImVec4(0.44f, 0.70f, 0.79f, 1.0f);

    // Inputs
    colors[ImGuiCol_FrameBg]         = ImVec4(0.86f, 0.93f, 0.97f, 1.0f);
    colors[ImGuiCol_FrameBgHovered]  = ImVec4(0.72f, 0.84f, 0.92f, 1.0f);
    colors[ImGuiCol_FrameBgActive]   = ImVec4(0.62f, 0.78f, 0.88f, 1.0f);

    // Headers 
    colors[ImGuiCol_Header]          = ImVec4(0.77f, 0.88f, 0.93f, 1.0f);
    colors[ImGuiCol_HeaderHovered]   = ImVec4(0.66f, 0.83f, 0.90f, 1.0f);
    colors[ImGuiCol_HeaderActive]    = ImVec4(0.53f, 0.77f, 0.85f, 1.0f);

    // Widgets e outros trem
    colors[ImGuiCol_Border]          = ImVec4(0.80f, 0.88f, 0.94f, 1.0f);
    colors[ImGuiCol_BorderShadow]    = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    colors[ImGuiCol_PopupBg]         = ImVec4(0.95f, 0.98f, 0.99f, 1.0f);
    colors[ImGuiCol_ScrollbarBg]     = ImVec4(0.90f, 0.95f, 0.97f, 1.0f);
    colors[ImGuiCol_ScrollbarGrab]   = ImVec4(0.67f, 0.84f, 0.90f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.53f, 0.77f, 0.85f, 1.0f);
    colors[ImGuiCol_ScrollbarGrabActive]  = ImVec4(0.44f, 0.70f, 0.79f, 1.0f);
    colors[ImGuiCol_CheckMark]       = ImVec4(0.33f, 0.58f, 0.72f, 1.0f);
    colors[ImGuiCol_SliderGrab]      = ImVec4(0.44f, 0.70f, 0.79f, 1.0f);
    colors[ImGuiCol_SliderGrabActive]= ImVec4(0.33f, 0.58f, 0.72f, 1.0f);

    // Fontes
    std::string relativePath = fs::current_path().u8string();
    const char* fontPath = relativePath.append("/media/Nunito-Light.ttf").c_str();
    std::cout << "Font found at: " << relativePath << std::endl;
    float fontSize = 14.0;
    io.Fonts->AddFontFromFileTTF(fontPath, fontSize); 

    // isso aqui eh pra teste vamo remover depois
    DummyModel model;
    DummyController controller(model);
    DummyView view(controller);
    MainContext mainCtx;

    // loop da aplicacao
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        view.render();
        mainCtx.DrawMainContext();

        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // rotina de encerramento
    // temos que adicionar codigo de permanencia de memoria depois
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
