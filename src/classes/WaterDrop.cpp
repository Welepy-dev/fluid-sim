#include "../../inc/WaterDrop.hpp"

WaterDrop::WaterDrop(Vector2 pos, Vector2 vel): _radius(WaterDropRadius) { this->_pos = pos; this->_vel = vel; }

WaterDrop::WaterDrop(const WaterDrop &other): _radius(other._radius) { this->_pos = other._pos; this->_vel = other._vel; }

WaterDrop &WaterDrop::operator=(const WaterDrop &other)
{ 
	if (this != &other)
	{
		this->_pos = other._pos; 
		this->_vel = other._vel; 
	}
	return *this;
}

WaterDrop::~WaterDrop( ) { }

void	WaterDrop::checkCollision(void)
{
	if (_pos.y + _radius >= WINDOW_HEIGHT)
	{
		_pos.y = WINDOW_HEIGHT - _radius;
		_vel.y *= -1 * DAMPING;
	}
	else if (_pos.y <= ORIGIN.y)
	{
		_pos.y = ORIGIN.y;
		_vel.y = 1 * DAMPING;
	}

	if (_pos.x + _radius >= WINDOW_WIDTH)
	{
		_pos.x = WINDOW_WIDTH - _radius;
		_vel.x *= -1 * DAMPING;
	}
	else if (_pos.x <= ORIGIN.x)
	{
		_pos.x = ORIGIN.x + _radius;
		_vel.x *= -1 * DAMPING;
	}
}

void	WaterDrop::render(void)
{
	// Apply gravity to velocity (acceleration)
	_vel += GRAVITY * GetFrameTime();
	
	// Update position based on velocity
	_pos += _vel * GetFrameTime();

	DrawCircleV(_pos, _radius, DARKBLUE);
	checkCollision();

}