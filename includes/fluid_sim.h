#ifndef FLUID_SIM_H
# define FLUID_SIM_H

#include <raylib.h>
#include <stdlib.h>
#include <math.h>
#include <raymath.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BOUND_SIZE (Vector2){SCREEN_WIDTH, SCREEN_HEIGHT}

int	Sign(float value);
void resolve_collisions(Vector2 *position, Vector2 *velocity, int radius);

float poly6_kernel(float r, float h);

void compute_density(Vector2 *positions, float *density, int num_particles, float h);

void render_particles(Vector2 *positions, float *density, int num_particles, float min_density, float max_density);
#endif
