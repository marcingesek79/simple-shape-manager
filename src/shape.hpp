#pragma once
#include <string>
#include "imgui.h"
#include "rlImGuiColors.h"

namespace Shapes {
    class Shape {
    public:
        Shape(char* label, int x, int y, ImVec4 color) : label{label}, x{x}, y{y}, color{rlImGuiColors::Convert(color)}, removed{false} {}
    
        [[nodiscard]] virtual double area() const = 0;
        virtual void draw() const = 0;

        [[nodiscard]] const std::string& getLabel() const {
            return label;
        }

        void remove() {
            removed = true;
        }

        [[nodiscard]] bool isRemoved() const {
            return removed;
        }
    
        virtual ~Shape() = default;
    
    protected:
        int x, y;
        Color color;
        std::string label;
        bool removed;
    };
}
