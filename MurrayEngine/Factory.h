#ifndef _FACTORY_H
#define	_FACTORY_H

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

#include	"Configuration.h"
#include	"Object.h"
#include	"Tile.h"
#include	"Map.h"
#include	"TextureAsset.h"
#include	"GameInstance.h"

class GameInstance;
class KeyController;

class Factory
{
public:
		Factory();
	virtual ~Factory();

	void	setWindow(SDL_Window* window);
	void	setGameInstance(GameInstance* instance);

	virtual Object*				createObject(Configuration config);
	Map*						createMap(Configuration config);
	TextureAsset*				createAsset(Configuration configuration);
	KeyController*				createKeyController(Configuration configuration);
	virtual std::shared_ptr<Animation>	createAnimation(Configuration configuarion);

private:

	SDL_Window*			window;
	SDL_Renderer*		renderer;
	GameInstance*		gameInstance;

};


#endif // !_FACTORY_H
