#include "Projectile.h"
#ifndef PROJECTILE_H
#define PROJECTILE_H

Projectile* Projectile::getInstance(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder) {

	return new Projectile(gameSession, FilePath, x, y, width, height, mapBorder);
}

Projectile::Projectile(Game* gameSessison, std::string FilePath, int x, int y, int width, int height, borders &mapBorder)
	:Sprite(gameSessison, FilePath, x, y, width, height, mapBorder) {


}

void Projectile::movement() {
	setY(getY() - 3);
	contact();
		
}



void Projectile::contact() {
	if (getY() < getBorder().mapUpperBorder || getY() > getBorder().mapLowerBorder) {
		setCollided(true);
	}

}


Projectile::~Projectile() {

}
#endif