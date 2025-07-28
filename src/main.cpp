#include "../inc/raylib.h"
#include "../inc/raymath.h"
#include "../inc/WaterDrop.hpp"

#include <cmath>
#include <vector>
#include <random>
#include <iostream>



int	main(void)
{
	InitWindow(1200, 800, "Fluid Simulation");

	WaterDrop droplet(Vector2{30, 30}, Vector2{15, 15});

	while (!WindowShouldClose())
	{
		
		BeginDrawing();

		ClearBackground(BLACK);

		droplet.render();

		EndDrawing();

	}

	CloseWindow();
	return 0;
}