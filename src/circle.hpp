#pragma once
#include <numbers>
#include "shape.hpp"

namespace Shapes {
    class Circle : public Shape {
    public:
        explicit Circle(char* label, int x, int y, float radius, ImVec4 color) : Shape{label, x, y, color}, radius{radius} {}
    
        double area() const override {
            return std::numbers::pi * radius * radius;
        }
    
        void draw() const override {
            DrawCircle(x, y, radius, color);
        }
    
    private:
        float radius;
    };
}