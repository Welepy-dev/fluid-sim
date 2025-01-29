#include "./includes/fluid_sim.h"

int	Sign(float value)
{
    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}

void resolve_collisions(Vector2 *position, Vector2 *velocity, int radius)
{
    float min_x = radius;
    float max_x = BOUND_SIZE.x - radius;
    float min_y = radius;
    float max_y = BOUND_SIZE.y - radius;
	float collision_damping = 0.85;

    if (position->x < min_x)
    {
        position->x = min_x;
        velocity->x *= -collision_damping; 
    }
    else if (position->x > max_x)
    {
        position->x = max_x;
        velocity->x *= -collision_damping;
    }

    if (position->y < min_y)
    {
        position->y = min_y;
        velocity->y *= -collision_damping * 0.85;
    }
    else if (position->y > max_y)
    {
        position->y = max_y;
        velocity->y *= -collision_damping * 0.85;
    }
}
