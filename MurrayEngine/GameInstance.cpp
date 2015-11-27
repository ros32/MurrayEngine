#include	"GameInstance.h"

#define		DEFAULT_FRAME_LIMIT		30

GameInstance::GameInstance()
{
	
}

GameInstance::GameInstance(SDL_Window* window, SDL_Renderer* renderer, Configuration configuration)
{
	this->frameLimiter = FrameLimiter(Timer(), configuration.getProperty("FRAME_LIMIT", DEFAULT_FRAME_LIMIT));
	this->instanceWindow = window;
	this->instanceRenderer = renderer;
	this->initialized = false;
	this->runned = false;
	this->exited = false;
}

GameInstance::~GameInstance()
{

}

bool GameInstance::initialize()
{
	this->initialized = true;
	return true;
}

bool GameInstance::run()
{
	while (1)
	{
		this->frameLimiter.start();
		//	Define SDL Event
		SDL_Event e;

		//	Poll for pending event into &e
		if (SDL_PollEvent(&e))
		{
			//	If Event Type is SDL_QUIT then break loop
			if (e.type == SDL_QUIT)
				break;
		}

		//	Clear renderer
		SDL_RenderClear(this->instanceRenderer);
		SDL_RenderPresent(this->instanceRenderer);

		this->frameLimiter.limit();
	}

	this->runned = true;
	return true;
}

bool GameInstance::exit()
{
	this->exited = true;
	return true;
}

void GameInstance::loadConfigurations()
{

}

bool GameInstance::isInitialized()
{
	return this->initialized;
}

bool GameInstance::isRun()
{
	return this->runned;
}

bool GameInstance::isExited()
{
	return this->exited;
}
