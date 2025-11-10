#pragma once
#include "imgui.h"
#include "shape.hpp"
#include "raylib.h"

namespace Shapes {
    class Rectangle : public Shape {
    public:
        explicit Rectangle(char* label, int x, int y, int a, int b, ImVec4 color) : Shape{label, x, y, color}, a{a}, b{b} {}

        double area() const override {
            return a * b;
        }
    
        void draw() const override {
            DrawRectangle(x, y, a, b, color);   
        }
    
    private:
        int a, b;
    };
}