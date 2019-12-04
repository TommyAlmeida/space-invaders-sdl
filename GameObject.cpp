#include "GameObject.h"

GameObject::GameObject(const char* texture, int xpos, int ypos, SDL_Renderer* renderer)
{
	this->renderer = renderer;
	this->texture = TextureManager::LoadTexture(texture, renderer);
	this->x = xpos;
	this->y = ypos;
}

GameObject::~GameObject()
{
	this->renderer = NULL;
	this->texture = NULL;
}

void GameObject::update()
{
	x++;
	y++;
	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = x;
	destRect.y = y;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
