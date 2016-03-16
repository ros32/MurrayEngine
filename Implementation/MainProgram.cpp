#include	<GameInstance.h>
#include	"ObjectFactory.h"

//	Default values are used if no configuration file is found
#define		DEFAULT_WINDOW_WIDTH	640
#define		DEFAULT_WINDOW_HEIGHT	480

#define	_DEBUG_FRAME_LIMIT		100
#define	_DEBUG_START_POS	=	{121, 333};

int main(int, char** argv)
{
	//	This is the main configuration file all game assets are loaded through
	Configuration mainConfig = Configuration("main.cfg");

	//	Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	//	Set logging priority. Use SDL_LOG_PRIORITY_CRITICAL for release
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_DEBUG);

	//	Create main window, get window height and width from configuration or use default if not found
	SDL_Window* mainWindow = SDL_CreateWindow(
		"MurrayEngine",
		100,
		100,
		mainConfig.getProperty("WINDOW_WIDTH", DEFAULT_WINDOW_WIDTH),
		mainConfig.getProperty("WINDOW_HEIGHT", DEFAULT_WINDOW_HEIGHT),
		SDL_WINDOW_SHOWN);

	//	Quit if main window failed to create
	if (mainWindow == nullptr)
		return 0;

	//	Initialize main renderer
	SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	//	Quit if main renderer failed to create
	if (mainRenderer == nullptr)
		return 0;

	//	Create game instance using main window, main renderer and main configuration file
	GameInstance* gameInstance = new GameInstance(mainWindow, mainRenderer, mainConfig);

	//	Create factory used to set up game assets and objects
	Factory*	  objectFactory = new ObjectFactory();

	//	Set factory in game instance
	gameInstance->setFactory(objectFactory);

	//	Initialize game by loading all assets, creating map and objects within
	gameInstance->initialize();

	//	When assets are initialized, we can set up keys

	//	Add keys to key controller
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_W, new PlayerMoveAction("Hero", gameInstance, NORTH), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_S, new PlayerMoveAction("Hero", gameInstance, SOUTH), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_A, new PlayerMoveAction("Hero", gameInstance, WEST), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_D, new PlayerMoveAction("Hero", gameInstance, EAST), true);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_SPACE, new DamageAction("Hero", gameInstance), false);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_RETURN, new ChangeInputModeAction(gameInstance->getKeyController()), false);
	gameInstance->getKeyController()->addAction(SDL_SCANCODE_F1, new ChangeMapAction(gameInstance, "SmallMap"), false);

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