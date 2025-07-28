#pragma once

# include "raylib.h"

#define WaterDropRadius 3

class WaterDrop
{
	public:
		WaterDrop(Vector2 pos, Vector2 vel);
		WaterDrop(const WaterDrop &other);
		WaterDrop &operator=(const WaterDrop &other);
		~WaterDrop();

		void	render(void);

	private:
		Vector2		_pos;
		Vector2		_vel;
		const int	_radius;

};