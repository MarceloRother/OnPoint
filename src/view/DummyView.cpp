#include "DummyView.hpp"
#include "../../include/imgui.h"

DummyView::DummyView(DummyController& controller) : controller(controller) {}

void DummyView::render() {
    ImGui::Begin("OnPoint");
    
    std::string currData = controller.fetchData();
    ImGui::Text("Data: %s", currData.c_str());

    ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.8f);

    static char buff[128] = "";
    if (ImGui::InputText("Edit Data", buff, IM_ARRAYSIZE(buff))) {
        controller.updateData(buff);
    }

    ImGui::End();
}
