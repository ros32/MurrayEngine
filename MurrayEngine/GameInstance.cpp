#include	"GameInstance.h"

GameInstance::GameInstance()
{
	
}

GameInstance::GameInstance(SDL_Window* window, SDL_Renderer* renderer, Configuration configuration)
{
	this->frameLimiter = FrameLimiter(Timer(), 30);
	this->instanceWindow = window;
	this->instanceRenderer = renderer;
}

GameInstance::~GameInstance()
{

}

bool GameInstance::initialize()
{
	return false;
}

bool GameInstance::run()
{
	return false;
}

bool GameInstance::exit()
{
	return false;
}

void GameInstance::loadConfigurations()
{

}
