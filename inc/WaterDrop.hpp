#pragma once

# include "raylib.h"

#define WaterDropRadius 5
#define GRAVITY (Vector2) {0, 98} 
#define Vector2DOWN (Vector2) {0, 1}
#define Vector2UP (Vector2) {0, -1}
#define Vector2LEFT (Vector2) {-1, 0}
#define Vector2RIGHT (Vector2) {1, 0}
#define ORIGIN (Vector2) {0, 0}			//Screen Origin
#define Vector2Zero (Vector2) {0, 0}
#define Vector2One (Vector2) {1, 1}
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 1200
#define DAMPING 0.49f
#define MAX_DROPLETS 1000

class WaterDrop
{
	public:
		WaterDrop(Vector2 pos, Vector2 vel);
		WaterDrop(const WaterDrop &other);
		WaterDrop &operator=(const WaterDrop &other);
		~WaterDrop();

		void	render(void);
		void	checkCollision(void);

	private:
		Vector2		_pos;
		Vector2		_vel;
		const int	_radius;

};
