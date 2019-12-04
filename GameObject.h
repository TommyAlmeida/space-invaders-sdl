#pragma once
#include "Game.h"

class GameObject
{
public:

	GameObject(const char* texture, int xpos, int ypos, SDL_Renderer* renderer);
	~GameObject();

	void update();
	void render();

private:
	int x, y;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

