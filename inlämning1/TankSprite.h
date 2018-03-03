#pragma once
#include "Sprite.h"
#include "borders.h"


class TankSprite: public Sprite{
	public:
		static TankSprite* getInstance(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder);
		void setX(int x);
		void setY(int y);
		bool contact(int cX, int cY, int cWidth, int cHeight);
		void movement(std::vector<Sprite*> &sprites);
	protected:
		TankSprite(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder);

		
		
};