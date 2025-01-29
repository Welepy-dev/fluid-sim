#include "./includes/fluid_sim.h"

const float gravity = 490.0f;
int scroll_speed = 10;
int number_of_particles = 5;
float radius = 10.0f;

Vector2 positions[5];
Vector2 velocities[5];

void update(Vector2 *position, Vector2 *velocity, float radius, int count)
{
    for (int i = 0; i < count; i++) 
    {
        velocity[i].y += gravity * GetFrameTime(); 
        position[i].y += velocity[i].y * GetFrameTime(); 
        position[i].x += velocity[i].x * GetFrameTime();

        // Ensure we're passing a single particle's position & velocity
        resolve_collisions(&position[i], &velocity[i], radius);
        DrawCircleV(position[i], radius, BLUE);
    }
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello, Raylib!");

    // Initialize positions and velocities
    for (int i = 0; i < number_of_particles; i++)
    {
        positions[i] = (Vector2){SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f};
        velocities[i] = (Vector2){0.0f, 0.0f};
    }

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText(TextFormat("Radius: %.2f", radius), 10, 10, 20, RAYWHITE);

        update(positions, velocities, radius, number_of_particles);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

