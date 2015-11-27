#ifndef _GAME_INSTANCE_H
#define	_GAME_INSTANCE_H

#include	"Asset.h"
#include	"Configuration.h"
#include	"FrameLimiter.h"
#include	"Viewport.h"
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

private:

	///	<summary>
	///	Do not allow creation of empty constructor
	/// </summary>
	GameInstance();

	std::map<std::string, Configuration> configurations;
	std::map<std::string, Asset> assets;

	//	Maybe these should be passed by the implementation instead?
	SDL_Window*		instanceWindow;
	SDL_Renderer*	instanceRenderer;

	FrameLimiter	frameLimiter;

	void			loadConfigurations();

	bool			initialized;
	bool			runned;
	bool			exited;




};

#endif // !_GAME_INSTANCE_H
