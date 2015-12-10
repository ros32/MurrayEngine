#ifndef _MAP_FACTORY_H
#define	_MAP_FACTORY_H

#include "GameInstance.h"
#include "Configuration.h"
#include "Map.h"

class GameInstance;

class MapFactory
{
public:
	MapFactory();
	MapFactory(SDL_Window* window, SDL_Renderer* renderer, GameInstance* gameInstance);
	~MapFactory();

	Map		createMap(Configuration config);

private:

	SDL_Window*		window;
	SDL_Renderer*	renderer;
	GameInstance*	gameInstance;

};

#endif // !_MAP_FACTORY_H
