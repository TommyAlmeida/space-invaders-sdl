#include "Game.h"
#include "GameObject.h"
#include "ECS.h"
#include "Components.h"

Manager manager;
auto& newPlayer(manager.addEntity());

GameObject* player;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SLD Not initialized! SDL ERROR" << SDL_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if (window == NULL) {
		std::cerr << "Could not create window" << SDL_GetError() << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	
	if (!renderer) {
		std::cerr << "Could not create renderer" << SDL_GetError() << std::endl;
		return;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);

	isRunning = true;
	player = new GameObject("assets/player.png", 0, 0, renderer);

	newPlayer.addComponent<PositionComponent>();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	cnt++;
	player->update();
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().x() << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
}

bool Game::running()
{
	return false;
}
