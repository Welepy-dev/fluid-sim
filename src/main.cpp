#include "../inc/raylib.h"
#include "../inc/WaterDrop.hpp"

int	main(void)
{
	InitWindow(600, 400, "Fluid Simulation");

	WaterDrop droplet(Vector2{30, 30}, Vector2{15, 15});

	while (!WindowShouldClose())
	{
		
		BeginDrawing();

		ClearBackground(DARKBLUE);

		DrawCircleV(droplet._pos, 15, YELLOW);

		EndDrawing();

	}

	CloseWindow();
	return 0;
}
