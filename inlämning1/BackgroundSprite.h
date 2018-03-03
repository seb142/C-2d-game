#pragma once
#include "Sprite.h"
#include "Collision.h"
#include "borders.h"

class BackgroundSprite : public Sprite {

	public:
		static BackgroundSprite* getInstance(Game* gameSession, std::string FilePath, int width, int height, borders& mapBorder);

	protected:
		BackgroundSprite(Game* gameSession, std::string FilePath, int width, int height, borders& mapBorder);

	private:
		
};