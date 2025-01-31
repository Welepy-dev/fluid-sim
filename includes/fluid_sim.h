#ifndef FLUID_SIM_H
# define FLUID_SIM_H

#include <raylib.h>
#include <stdlib.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BOUND_SIZE (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT}

int	Sign(float value);
void resolve_collisions(Vector2 *position, Vector2 *velocity, int radius);

#endif
