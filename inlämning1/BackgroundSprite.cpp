#include "BackgroundSprite.h"
#ifndef BACKGROUNDSPRITE_H
#define BACKGROUNDSPRITE_H

BackgroundSprite::BackgroundSprite(Game* gameSessison, std::string FilePath, int width, int height, borders &mapBorder):Sprite(gameSessison, FilePath, 0, 0, width, height, mapBorder) {

}

BackgroundSprite* BackgroundSprite::getInstance(Game* gameSession, std::string FilePath, int width, int height, borders& mapBorder) {

	return new BackgroundSprite(gameSession, FilePath, width, height, mapBorder);
}
#endif
