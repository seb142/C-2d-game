#pragma once
#include "Sprite.h"
#include "Projectile.h"
#include "borders.h"
#include <vector>
#include <iostream>
#include <memory>

class GameLoop;
class Enemy : public Sprite {
public:
	~Enemy();
	static Enemy* getInstance(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder);
	void movement(std::vector<Sprite*> &sprites);
	void contact(int cX, int cY, int cWidth, int cHeight);
	

protected:
	Enemy(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder);

private:

};
