#include "raylib.h"
#include "rlImGui.h"

#include "shape_manager.hpp"
#include "shape_manager_window.hpp"

int main()
{
	constexpr int SCREEN_WIDTH = 1280;
	constexpr int SCREEN_HEIGHT = 800;
	constexpr int FPS = 144;

	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple Shape Manager");
	SetTargetFPS(FPS);
	rlImGuiSetup(true);

	ShapeManager shape_manager{};
	ShapeManagerWindow shape_manager_window{shape_manager};

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		rlImGuiBegin();

		shape_manager.drawAllShapes();
		shape_manager_window.show();

		rlImGuiEnd();
		EndDrawing();
	}
 
    rlImGuiShutdown();
	CloseWindow();

	return 0;
}