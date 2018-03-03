#pragma once
#include <string>
#include <iostream>
#include <SDL.h>

class Game {

public:
	Game();
	~Game();
	SDL_Renderer* getRenderer();
	void renderClear();
	void renderPresent();
	SDL_Event* getMainEvent();

private:
	bool run;
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event* mainEvent;
	SDL_Texture* dirt_bkg;
	SDL_Texture* tank;
	SDL_Rect* dirtRectangle;
	SDL_Rect* tankRectangle;
};
