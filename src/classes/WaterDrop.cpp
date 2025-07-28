#include "../../inc/WaterDrop.hpp"

WaterDrop::WaterDrop(Vector2 pos, Vector2 vel): _radius(WaterDropRadius) { this->_pos = pos; this->_vel = vel; }

WaterDrop::~WaterDrop( ) { }

void	WaterDrop::render(void) { DrawCircleV(_pos, _radius, DARKBLUE); }