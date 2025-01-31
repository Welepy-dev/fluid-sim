#include "./includes/fluid_sim.h"

float poly6_kernel(float r, float h)
{
    if (r >= h) return 0.0f;
    float coeff = 315.0f / (64.0f * PI * powf(h, 9));
    return coeff * powf((h * h - r * r), 3);
}

void compute_density(Vector2 *positions, float *density, int num_particles, float h)
{
    for (int i = 0; i < num_particles; i++)
    {
        density[i] = 0.0f;  // Reset density

        for (int j = 0; j < num_particles; j++)
        {
            if (i == j) continue; // Skip itself

            float dist = Vector2Distance(positions[i], positions[j]); // Distance between particles
            density[i] += poly6_kernel(dist, h);
        }
    }
}

void render_particles(Vector2 *positions, float *density, int num_particles, float min_density, float max_density)
{
    for (int i = 0; i < num_particles; i++)
    {
        float normalized_density = (density[i] - min_density) / (max_density - min_density);
        Color color = ColorFromHSV(220, 1.0f, normalized_density); // Smooth color based on density
        DrawCircleV(positions[i], 5, color);
    }
}

