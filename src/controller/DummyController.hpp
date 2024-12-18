#pragma once
#include "../model/DummyModel.hpp"
#include <string>

class DummyController {
public:
    DummyController(DummyModel& model) : model(model) {}

    void updateData(const std::string& data) {
        model.setData(data);
    }

    std::string fetchData() const {
        return model.getData();
    }

private:
    DummyModel& model;
};
