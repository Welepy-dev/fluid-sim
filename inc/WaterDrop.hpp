#pragma once

# include "raylib.h"

class WaterDrop
{
	public:
		WaterDrop();
		WaterDrop(Vector2 pos, Vector2 vel);
		WaterDrop(const WaterDrop &);
		WaterDrop &operator=(const WaterDrop &);
		~WaterDrop();
	
		Vector2	_pos;
		Vector2 _vel;
	
	private:

};

