#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	int cnt;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

