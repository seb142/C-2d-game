#include "Enemy.h"
using namespace std;
#ifndef ENEMY_H
#define ENEMY_H

Enemy::~Enemy() {}
Enemy::Enemy(Game* gameSessison, std::string FilePath, int x, int y, int width, int height, borders &mapBorder)
	:Sprite(gameSessison, FilePath, x, y, width, height, mapBorder) {

}

Enemy* Enemy::getInstance(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder) {
	return new Enemy(gameSession, FilePath, x, y, width, height, mapBorder);

}

void Enemy::movement(vector<Sprite*> &sprites) {
	if(getY()+getHeight() < getBorder().mapLowerBorder){
		setY(getY() + 1);
	}
	else {
		setCollided(true);
		return;
	}
	for (int i = 0; i < sprites.size(); i++) {
		if (Projectile* e = dynamic_cast<Projectile*>(sprites[i])) {
			contact(e->getX(), e->getY(), e->getWidth(), e->getHeight());
			if(getCollided()) {
				e->setCollided(true);
				break;
			}
		}
	}
}

void Enemy::contact(int cX, int cY, int cWidth, int cHeight) {
	if (cX + cWidth > getRect()->x && cX < getRect()->x + (getRect()->w) && cY < (getRect()->y + getRect()->h) && cY + cHeight / 2 > (getRect()->y)) {
		setCollided(true);
	}


}
#endif 