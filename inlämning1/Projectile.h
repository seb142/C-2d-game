#pragma once
#include "Sprite.h"
#include "Collision.h"
#include <iostream>
#include "BackgroundSprite.h"
class Projectile : public Sprite {

public:
	~Projectile();
	static Projectile* getInstance(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder);
	void movement();
	void contact();

protected:
	Projectile(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder);

private:
	SDL_Texture* image;
	bool collided = false;
};