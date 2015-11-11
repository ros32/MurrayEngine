#ifndef _GAME_INSTANCE_H
#define	_GAME_INSTANCE_H

#include	"Configuration.h"
#include	"FrameLimiter.h"
#include	"Viewport.h"
#include	<SDL.h>

class GameInstance
{
public:
	GameInstance();
	~GameInstance();

	bool			initialize();
	bool			run();
	bool			exit();

//	bool			save();
//	bool			load();

	bool			isInitialized();
	bool			isRun();
	bool			isExited();

private:

	Configuration	debugConfig;
	Configuration	clientConfig;
	Configuration	engineConfig;

	//	Maybe these should be passed by the implementation instead?
	SDL_Window*		instanceWindow;
	SDL_Renderer*	instanceRenderer;

	FrameLimiter	frameLimiter;

	void			loadConfigurations();




};

#endif // !_GAME_INSTANCE_H
