#pragma once
#include "GameLoop.h"
#include "Game.h"
#include <iostream>
#include "BackgroundSprite.h"
#include "TankSprite.h"
#include "Projectile.h"
#ifndef GAMELOOP_H
#define GAMELOOP_H

using namespace std;
 
GameLoop::~GameLoop() {}

GameLoop::GameLoop(Game *gameSession, BackgroundSprite* background, TankSprite* tank, int FPS,vector <Sprite*> enemies, borders mapBorder) {

	run = false;

	int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	Projectile* projectile = NULL;
	int shootTimer = 0;
	int spawnTimer = 0;
	int v1=0;
	vector<Enemy*> enemiesDead;

	while (!run && gameSession->getMainEvent()->type != SDL_QUIT) {
		shootTimer++;
		spawnTimer++;

		if (spawnTimer == 70) {
			spawnTimer = 0;
			if (enemiesDead.size() != 0) {
				v1 = rand() % enemiesDead.size();
				enemiesDead[v1]->setCollided(false);
				enemiesDead[v1]->setY(40);
				enemies.push_back(enemiesDead[v1]);
				enemiesDead.erase(enemiesDead.begin() + v1);
			}

		}


		frameStart = SDL_GetTicks();

		SDL_PollEvent(gameSession->getMainEvent());
		gameSession->renderClear();
		background->Draw(gameSession);



		vector<Sprite*>::iterator it;
		for (it = enemies.begin(); it != enemies.end(); ) {

			if (Enemy * e = dynamic_cast<Enemy*>(*it)) {
				if (e->getY() + e->getWidth() >= mapBorder.mapLowerBorder) {
					run = true;
				}

				e->movement(enemies);
				e->Draw(gameSession);
				if (e->getCollided()) {
					enemiesDead.push_back(e);
					enemies.erase(it);
					break;
				}


			}
			if (Projectile * p = dynamic_cast<Projectile*>(*it)) {
				p->movement();
				p->Draw(gameSession);
				if (p->getCollided()) {
					p->~Projectile();
					enemies.erase(it);
					break;
				}

			}

			it++;
		}

		switch (gameSession->getMainEvent()->type)
		{
		case SDL_KEYDOWN:

			switch (gameSession->getMainEvent()->key.keysym.sym)
			{

			case SDLK_UP:
				tank->setY(tank->getY() - 4);
				break;

			case SDLK_DOWN:
				tank->setY(tank->getY() + 4);
				break;

			case SDLK_RIGHT:
				tank->setX(tank->getX() + 4);
				break;

			case SDLK_LEFT:
				tank->setX(tank->getX() - 4);
				break;

			case SDLK_SPACE:
				if (shootTimer > 30) {
					enemies.push_back(projectile = Projectile::getInstance(gameSession, "assets/Projectile.png", tank->getX() + (tank->getWidth() / 2 - 10), tank->getY(), 20, 50, mapBorder));
					shootTimer = 0;
				}
				break;

			default:
				break;
			}
		}
		tank->movement(enemies);
		tank->Draw(gameSession);
		if (tank->getCollided()) {
			run = true;
			std::cout << "#################" << std::endl;
		}	
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {

			SDL_Delay(frameDelay - frameTime);  
		}
		gameSession->renderPresent();
	}


	for (int i = 0; i < enemies.size(); i++) {

		if (Projectile * p = dynamic_cast<Projectile*>(enemies[i])) {
			delete p;

		}
	}

	
}
#endif
