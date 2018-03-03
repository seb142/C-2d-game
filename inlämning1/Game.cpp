#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
#include "Game.h"
#include <SDL_image.h>
#ifndef GAME_H
#define GMAE_H
using namespace std;

Game::Game() {

	window = nullptr;
	run = false;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = NULL;
		window = SDL_CreateWindow("Spaceships", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 640, 800, SDL_WINDOW_OPENGL);
		renderer = NULL;
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		mainEvent = new SDL_Event();
						
	}
}


void Game::renderClear() {
	SDL_RenderClear(renderer);
	
	//cout << "while iteration" << endl;
}
void Game::renderPresent() {

	SDL_RenderPresent(renderer);
}

Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Event* Game::getMainEvent()
{
	return mainEvent;
}

SDL_Renderer* Game::getRenderer() {


	return renderer;
}
#endif