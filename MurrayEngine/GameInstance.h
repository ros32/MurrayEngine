#ifndef _GAME_INSTANCE_H
#define	_GAME_INSTANCE_H

#include	<memory>
#include	"MapFactory.h"
#include	"Asset.h"
#include	"Configuration.h"
#include	"FrameLimiter.h"
#include	"Camera.h"
#include	"TextureAsset.h"
#include	"TextureAssetFactory.h"
#include	"InvalidAsset.h"
#include	"Map.h"
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include	"Action.h"
#include	"JumpAction.h"
#include	"MoveAction.h"
#include	"Factory.h"
#include	"KeyController.h"
#include	<SDL_ttf.h>
#include	"NonPlayerCharacter.h"
#include	"AI.h"
#include	"DefaultAI.h"

class Factory;
class KeyController;

struct KeyState
{
	bool	key_w = false;
	bool	key_s = false;
	bool	key_a = false;
	bool	key_d = false;
	bool	key_left = false;
	bool	key_right = false;
	bool	key_up = false;
	bool	key_down = false;
	bool	key_space = false;
};


///	<summary>
///	GameInstance controls the current instance of a game. It consists of all assets and objects, and controls the state of the game.
///</summary>
class GameInstance
{
public:
	GameInstance();
	GameInstance(SDL_Window* window, SDL_Renderer* renderer, Configuration configuration);
	~GameInstance();

	///	<summary>
	///	Initialize the GameInstance, loading all assets and models into memory from Configuration
	///	</summary>
	bool			initialize();

	///	<summary>
	///	Run the GameInstance, which starts the execution of the actual game.
	///	</summary>
	bool			run();

	///	<summary>
	///	Do Post-run stuff before exiting the GameInstance
	///	</summary>
	bool			exit();

	///	<summary>
	///	Save the GameInstance to file to restore later
	///	</summary>
//	bool			save();

	///	<summary>
	///	Load GameInstance from a file
	///	</summary>
//	bool			load();

	bool			isInitialized();
	bool			isRun();
	bool			isExited();

	Map*			getMap();
	void			setMap(Map* map);

	TextureAsset*		getTextureAsset(std::string name);

	void				setFactory(Factory* factory);
	Factory*			getFactory();

	KeyController*		getKeyController();
	void				setKeyController(KeyController* keyController);

private:

	///	<summary>
	///	Do not allow creation of empty constructor
	/// </summary>
	

	std::map<std::string, Configuration> configurations;
	std::map<std::string, Asset*> assets;
	std::map<std::string, TextureAsset*> textureAssets;

	//	Maybe these should be passed by the implementation instead?
	SDL_Window*		instanceWindow;
	SDL_Renderer*	instanceRenderer;

	FrameLimiter	frameLimiter;

	Configuration	mainConfig;

	void			loadConfigurations();
	void			renderObjects();
	void			moveObjects();
	void			doActions();

	bool			initialized;
	bool			runned;
	bool			exited;

	Map*			map;

	KeyState		keyState;

	Factory*		factory;

	KeyController*	keyController;

	GUIObject*		frameRateGUIObject;

};

#endif // !_GAME_INSTANCE_H
