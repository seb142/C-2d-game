  #pragma once
#include <SDL.h>
#include <stdio.h>
#include "borders.h"
#include "Game.h"
#include "Main.h"
#include "GameLoop.h"
#include "Sprite.h"
#include "BackgroundSprite.h"
#include "TankSprite.h"
#include "Enemy.h"
#include "Projectile.h"
#include <vector>


using namespace std;


int main(int argc, char * argv[])
{
	
	vector<Sprite*> enemies;
	int FPS = 60;
	int mapUpperBorder = 0;
	int mapLowerBorder = 800;
	int mapLeftBorder = 0;
	int mapRightBorder = 640;
	borders border;
	border.mapUpperBorder = 0;
	border.mapLowerBorder = 800;
	border.mapLeftBorder = 0;
	border.mapRightBorder = 640;
	borders& mapBorder = border;


	Game* gameSession = new Game();
	BackgroundSprite* background = BackgroundSprite::getInstance(gameSession, "assets/Starfield.png",640,800, mapBorder);
	TankSprite* tank = TankSprite::getInstance(gameSession, "assets/Spaceship_player.png", 300, 660, 90, 130, mapBorder);
	Enemy* enemy1 = Enemy::getInstance(gameSession, "assets/Spaceship_enemy1.png", 400, 70, 90, 90, mapBorder);
	Enemy* enemy2 = Enemy::getInstance(gameSession, "assets/Spaceship_enemy1.png", 300, 70, 90, 90, mapBorder);
	Enemy* enemy3 = Enemy::getInstance(gameSession, "assets/Spaceship_enemy1.png", 200, 70, 90, 90, mapBorder);
	Enemy* enemy4 = Enemy::getInstance(gameSession, "assets/Spaceship_enemy1.png", 100, 70, 90, 90, mapBorder);

	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);


	GameLoop *gameLoop = new GameLoop(gameSession, background, tank, FPS, enemies, mapBorder);

	delete gameSession;
	delete background;
	delete tank;
	delete enemy1;
	delete enemy2;
	delete enemy3;
	delete enemy4;
	delete gameLoop;

	return 0;
}