#pragma once
#include "Game.h"
#include "BackgroundSprite.h"
#include "Enemy.h"
#include "TankSprite.h"
#include "Sprite.h"

using namespace std;
class Enemy;
class GameLoop
{
public:
	GameLoop(Game* gameSession, BackgroundSprite* background, TankSprite* tank, int FPS, vector <Sprite*> enemies, borders mapBorder);
	~GameLoop();

private:
	bool run;
	int FPS;
	GameLoop(const GameLoop& other) = delete;
	const GameLoop& operator=(const GameLoop& other);
	vector<Projectile*> projectileList;
	vector<Enemy*>::iterator it;
	borders border;
};


