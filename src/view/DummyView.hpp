#pragma once
#include "../controller/DummyController.hpp"

class DummyView {
public:
    DummyView(DummyController& controller);
    void render();

private:
    DummyController& controller;
};
