#pragma once
#include <string>

class DummyModel {
public: 
    void setData(const std::string& data) {this->data = data;}
    std::string getData() const {return data;}
private:
    std::string data = "Hello, OnPoint";
};
