// SpaceInvadersSDL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "Game.h"

#undef main

const char* TITLE = "Space Invaders";
const int WIDTH = 1280, HEIGHT = 720, FPS = 60, FRAME_DELAY = 1000 / FPS;

Game* game = nullptr;

int main()
{
	game = new Game();
	game->init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);

	Uint32 frameStart;
	int frameTime;

	while (!game->running()) {
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	game->clean();

	return EXIT_SUCCESS;
}
