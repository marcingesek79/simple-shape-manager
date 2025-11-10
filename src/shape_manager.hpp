#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include "shape.hpp"

class ShapeManager {
public:
    template <typename T>
    void addShape(T&& shape) {
        shapes.push_back(std::make_unique<T>(std::forward<T>(shape)));
        shape_count++;
    }

    void drawAllShapes(){
        removeShapes();
        for (const auto& shape : shapes) {
            if (not shape->isRemoved()) {
                shape->draw();
            }   
        }
    }

    void removeShapeByLabel(const std::string& label) {
        auto itr = std::find_if(shapes.begin(), shapes.end(),
            [&label](const std::unique_ptr<Shapes::Shape>& shape) {
                return shape->getLabel() == label;
            });
        itr->get()->remove();
        shape_count--;
    }

    [[nodiscard]] static int getShapeCount() {
        return shape_count;
    }

    [[nodiscard]] const std::vector<std::unique_ptr<Shapes::Shape>>& getShapes() const {
        return shapes;
    }

    [[nodiscard]] std::vector<std::unique_ptr<Shapes::Shape>>& getShapes() {
        return shapes;
    }

private:
    void removeShapes() {
        shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
            [](const std::unique_ptr<Shapes::Shape>& shape) {
                return shape->isRemoved();
            }), shapes.end());
    };

    std::vector<std::unique_ptr<Shapes::Shape>> shapes{};
    static inline int shape_count = 0;
};
