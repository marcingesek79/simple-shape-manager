#pragma once
#include "shape.hpp"
#include "raylib.h"
#include "imgui.h"

namespace Shapes {
    class Square : public Shape {
    public:
        explicit Square(char* label, int x, int y, int size, ImVec4 color) : Shape{label, x, y, color}, size{size} {}
    
        double area() const override {
            return size * size;
        }
    
        void draw() const override {
            DrawRectangle(x, y, size, size, color);
        }

    private:
        int size;
    };
}
