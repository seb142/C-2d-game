#include "TankSprite.h"
#include "Enemy.h"
#ifndef TANKSPRITE_H
#define TANKSPRITE_H
using namespace std;

TankSprite* TankSprite::getInstance(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder) {

	return new TankSprite(gameSession, FilePath, x, y, width, height, mapBorder);
}

TankSprite::TankSprite(Game* gameSessison, std::string FilePath, int x, int y, int width, int height, borders &mapBorder)
	:Sprite(gameSessison, FilePath, x, y, width, height, mapBorder) {
	
}

void TankSprite::movement(vector<Sprite*> &sprites) {

	for (int i = 0; i < sprites.size(); i++) {
		if (Enemy* e = dynamic_cast<Enemy*>(sprites[i])) {
			contact(e->getX(), e->getY(), e->getWidth(), e->getHeight());
			
		}
	}
}

bool TankSprite::contact(int cX, int cY, int cWidth, int cHeight) {

	
	if (cX + cWidth > getRect()->x && cX < getRect()->x + (getRect()->w) &&  cY + cHeight > getRect()->y && getRect()->y + getRect()->h > cY) {
		setCollided(true);
		std::cout << "-----++------" << std::endl;
		return true;
	}
	else {
		return false;
	}
	

}

void TankSprite::setX(int x) {
	if (getBorder().mapLeftBorder < x && getBorder().mapRightBorder > x + getWidth()) {
		getRect()->x = x;
	}
}

void TankSprite::setY(int y) {
	if (getBorder().mapUpperBorder < y && getBorder().mapLowerBorder > y + getHeight()) {
		getRect()->y = y;
	}
}
#endif