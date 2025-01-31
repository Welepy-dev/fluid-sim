#include "./includes/fluid_sim.h"

const float gravity = 490.0f;
int scroll_speed = 10;
int number_of_particles = 5;
float radius = 2.5f;
float particle_size = 100.0f;
float particle_spacing = 250.0f;
bool paused = false;


void update(Vector2 *position, Vector2 *velocity, float radius, int count)
{
		for (int i = 0; i < count; i++) 
		{
			velocity[i].y += gravity * GetFrameTime(); 
			position[i].y += velocity[i].y * GetFrameTime(); 
			position[i].x += velocity[i].x * GetFrameTime();

			resolve_collisions(&position[i], &velocity[i], radius);
			DrawCircleV(position[i], radius, BLUE);
		}
}

int random_int(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void initial_pos(Vector2 *positions)
{
	for (int i = 0; i < number_of_particles; i++)
		positions[i] = (Vector2){random_int(0, SCREEN_WIDTH) , random_int(0, SCREEN_HEIGHT)};
}

int main(int ac, char **av)
{
	if (ac == 2)
		number_of_particles = atoi(av[1]);
	float density[number_of_particles];
	float smoothing_radius = 30.f;
	Vector2 *positions;
	Vector2 *velocities;
	positions = malloc(sizeof(Vector2) * number_of_particles);
	velocities = malloc(sizeof(Vector2) * number_of_particles);
	//start(positions);
	initial_pos(positions);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello, Raylib!");

	for (int i = 0; i < number_of_particles; i++)
		velocities[i] = (Vector2){0.0f, 0.0f};

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        BeginDrawing();
		if(IsKeyPressed(KEY_SPACE))
			paused = !paused;
		if (paused)
		{
        	ClearBackground(BLACK);
			compute_density(positions, density, number_of_particles, smoothing_radius);
			render_particles(positions, density, number_of_particles, 0.0f, 1.0f);

			DrawText(TextFormat("Radius: %.2f", radius), 10, 10, 20, RAYWHITE);

			update(positions, velocities, radius, number_of_particles);

    	}
		EndDrawing();
	}

	free(positions);
	free(velocities);
    CloseWindow();
    return 0;
}
