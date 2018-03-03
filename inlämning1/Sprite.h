#pragma once
#include <SDL.h>
#include "Game.h"
#include <vector>
#include <iostream>
#include <memory>
#include "borders.h"
#include <SDL_image.h>

class Sprite {

	public:
		
		~Sprite();
		virtual void Draw(Game* gameSessison);
		virtual void setX(int x);
		virtual void setY(int y);
		virtual void movement();
		borders getBorder();
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		bool getCollided();
		void setCollided(bool c);
		SDL_Rect* getRect();
	protected:
		Sprite(Game* gameSession, std::string FilePath, int x, int y, int width, int height, borders &mapBorder);
	private:
		Sprite(const Sprite& other) = delete;
		const Sprite& operator = (const Sprite& other);
		SDL_Texture* image;
		SDL_Rect* rectangle;
		borders& border;
		bool collided = false;
	
};