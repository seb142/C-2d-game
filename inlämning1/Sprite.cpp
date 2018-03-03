#include "Sprite.h";
#ifndef SPRITE_H
#define SPRITE_H
using namespace std;

Sprite::~Sprite() {
	SDL_DestroyTexture(image);
}

Sprite::Sprite(Game* gamseSessison, std::string FilePath, int x, int y, int width, int height, borders& mapBorder):border(mapBorder){
	image = NULL;
	image = IMG_LoadTexture(gamseSessison->getRenderer(), FilePath.c_str());
	rectangle = NULL;
	rectangle = new SDL_Rect;
	rectangle->x = x;
	rectangle->y = y;
	rectangle->w = width;
	rectangle->h = height;
}

void Sprite::movement() {

}



void Sprite::setX(int x){
	rectangle->x = x;
}

void Sprite::setY(int y) {
	rectangle->y = y;
}

borders Sprite::getBorder() {
	return border;
}

int Sprite::getX() {
	return rectangle->x;
}

int Sprite::getY() {
	return rectangle->y;
}
int Sprite::getWidth() {
	return rectangle->w;
}

int Sprite::getHeight() {
	return rectangle->h;
}

void Sprite::Draw(Game* gameSessison){
	SDL_RenderCopy(gameSessison->getRenderer(),image ,NULL,rectangle);
}

SDL_Rect* Sprite::getRect() {
	return rectangle;
}

bool Sprite::getCollided() {
	return collided;
}

void Sprite::setCollided(bool c) {
	collided = c;
}
#endif