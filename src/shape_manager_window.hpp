#pragma once
#include "imgui.h"
#include "shape_manager.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

class ShapeManagerWindow {
public:
    explicit ShapeManagerWindow(ShapeManager& manager) : shape_manager{manager} {}

    void show() {
        ImGui::Begin("Shape Manager");
		ImGui::Text("Total shapes: %d", shape_manager.getShapeCount());
		ImGui::Spacing();
		drawShapeMenu();
        ImGui::Spacing();
        drawShapeInstancesMenu();
		ImGui::End();
    }

private:
    void drawShapeMenu() {
        if (ImGui::TreeNode("Add a new shape")){
			drawSquareHandler();
            drawRectangleHandler();
            drawCircleHandler();
			ImGui::TreePop();
		}
    }

    void drawSquareHandler() {
        if (ImGui::TreeNode("Square"))
        {
            static char buf[32] = "Square\0";
            ImGui::InputText("Label", buf, 32);

            static int size = 100;
            ImGui::InputInt("Size", &size, 10, 100);
            
            static int x = 0, y = 0;
            drawPosMenu(x, y);

            static ImVec4 color{1, 1, 1, 1};
            drawColorMenu(color);

            ImGui::SameLine();
            if (ImGui::Button("Add Square")) {
                shape_manager.addShape(Shapes::Square{buf, x, y, size, color});
            }

            ImGui::TreePop();
        }
    }

    void drawRectangleHandler() {
        if (ImGui::TreeNode("Rectangle"))
        {
            static char buf[32] = "Rectangle\0";
            ImGui::InputText("Label:", buf, 32);

            static int a = 100, b = 100;
            ImGui::InputInt("Width", &a, 10, 100);
            ImGui::InputInt("Height", &b, 10, 100);
            
            static int x = 0, y = 0;
            drawPosMenu(x, y);

            static ImVec4 color{1, 1, 1, 1};
            drawColorMenu(color);

            ImGui::SameLine();
            if (ImGui::Button("Add Rectangle")) {
                shape_manager.addShape(Shapes::Rectangle{buf, x, y, a, b, color});
            }

            ImGui::TreePop();
        }
    }

    void drawCircleHandler() {
        if (ImGui::TreeNode("Circle"))
        {
            static char buf[32] = "Circle\0";
            ImGui::InputText("Label", buf, 32);

            static float radius = 50.0f;
            ImGui::InputFloat("Radius", &radius, 5, 25);
            
            static int x = 0, y = 0;
            drawPosMenu(x, y);

            static ImVec4 color{1, 1, 1, 1};
            drawColorMenu(color);

            ImGui::SameLine();
            if (ImGui::Button("Add Circle")) {
                shape_manager.addShape(Shapes::Circle{buf, x, y, radius, color});
            }

            ImGui::TreePop();
        }
    }

    void drawPosMenu(int& x, int& y) {
        ImGui::InputInt("X Pos", &x, 10, 50);
        ImGui::InputInt("Y Pos", &y, 10, 50);
    }

    void drawColorMenu(ImVec4& color) {
        ImGui::ColorEdit4("Color:", reinterpret_cast<float*>(&color), ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
    }

    void drawShapeInstancesMenu() {
        if (ImGui::TreeNode("Shape Instances"))
        {
            for (const auto& shape : shape_manager.getShapes()) {
                if (not shape->isRemoved() && ImGui::TreeNode(shape->getLabel().c_str())) {
                    ImGui::Text("Area: %.1f", shape->area());
                    drawRemoveButton(shape->getLabel());
                    ImGui::TreePop();
                }
            }
            ImGui::TreePop();
        }
    }

    void drawRemoveButton(const std::string& label) {
        if (ImGui::Button("Remove")) {
            shape_manager.removeShapeByLabel(label);
        }
    }

    ShapeManager& shape_manager;
};