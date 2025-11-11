
set(imgui_SOURCES
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
)

add_library(imgui OBJECT ${imgui_SOURCES})
add_library(rlimgui OBJECT ${rlimgui_SOURCE_DIR}/rlImGui.cpp)
target_link_libraries(rlimgui raylib)

include_directories(${imgui_SOURCE_DIR})
include_directories(${rlimgui_SOURCE_DIR})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} raylib imgui rlimgui)
