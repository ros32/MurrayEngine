#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
//#include	<vld.h>
#include	<SDL.h>
#include	<GameInstance.h>
#include	"ObjectFactory.h"

#define		DEFAULT_WINDOW_WIDTH	640
#define		DEFAULT_WINDOW_HEIGHT	480

#define	_DEBUG_FRAME_LIMIT		100
#define	_DEBUG_START_POS	=	{121, 333};

int main(int, char** argv)
{
	Configuration mainConfig = Configuration("main.cfg");

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_INFO);
	SDL_Window* mainWindow = SDL_CreateWindow(
		"MurrayEngine",
		100,
		100,
		mainConfig.getProperty("WINDOW_WIDTH", DEFAULT_WINDOW_WIDTH),
		mainConfig.getProperty("WINDOW_HEIGHT", DEFAULT_WINDOW_HEIGHT),
		SDL_WINDOW_SHOWN);

	if (mainWindow == nullptr)
		return 0;

	SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	if (mainRenderer == nullptr)
		return 0;

	//	Create game instance
	GameInstance* gameInstance = new GameInstance(mainWindow, mainRenderer, mainConfig);
	Factory*	  objectFactory = new ObjectFactory();
	gameInstance->setFactory(objectFactory);

	//	Initialize game by loading all configuration files
	gameInstance->initialize();

	//	Add keys to key controller
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_W, new MoveAction(gameInstance->getMap()->getPlayerCharacter(), gameInstance->getMap(), NORTH), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_S, new MoveAction(gameInstance->getMap()->getPlayerCharacter(), gameInstance->getMap(), SOUTH), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_A, new MoveAction(gameInstance->getMap()->getPlayerCharacter(), gameInstance->getMap(), WEST), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_D, new MoveAction(gameInstance->getMap()->getPlayerCharacter(), gameInstance->getMap(), EAST), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_SPACE, new DamageAction(gameInstance->getMap()->getPlayerCharacter(), gameInstance->getMap()), false);

	bool quitGame = false;
	while (!quitGame)
	{
		if (!gameInstance->isInitialized())
			gameInstance->initialize();

		gameInstance->run();

		if (!gameInstance->isExited())
		{
			gameInstance->exit();
			delete gameInstance;
			_CrtDumpMemoryLeaks();
			quitGame = true;
		}
	}





	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}