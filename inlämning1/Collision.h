#pragma once
#include <SDL.h>
class Collision
{
public: 
	Collision();
	Collision(int x, int y, int width, int height);
	void setCollisionArea(int x, int y, int width, int height);
	void setX(int x);
	void setY(int y);
	SDL_Rect getCollision();
private: 
	SDL_Rect CollRectangle;
	int collX;
	int collY; 
	int collWidth;
	int collHeight;




};