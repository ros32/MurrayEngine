#ifndef _GAME_INSTANCE_H
#define	_GAME_INSTANCE_H

#include	"Asset.h"
#include	"Configuration.h"
#include	"FrameLimiter.h"
#include	"Camera.h"
#include	"TextureAsset.h"
#include	"TextureAssetFactory.h"
#include	"InvalidAsset.h"
#include	"Map.h"
#include	<SDL.h>

///	<summary>
///	GameInstance controls the current instance of a game. It consists of all assets and objects, and controls the state of the game.
///</summary>
class GameInstance
{
public:
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

	void			setMap(Map map);

	TextureAsset*				getTextureAsset(std::string name);

private:

	///	<summary>
	///	Do not allow creation of empty constructor
	/// </summary>
	GameInstance();

	std::map<std::string, Configuration> configurations;
	std::map<std::string, Asset> assets;
	std::map<std::string, TextureAsset> textureAssets;

	//	Maybe these should be passed by the implementation instead?
	SDL_Window*		instanceWindow;
	SDL_Renderer*	instanceRenderer;

	FrameLimiter	frameLimiter;

	Configuration	mainConfig;

	void			loadConfigurations();
	void			renderObjects();
	void			moveObjects();

	bool			initialized;
	bool			runned;
	bool			exited;

	Map				map;


};

#endif // !_GAME_INSTANCE_H
