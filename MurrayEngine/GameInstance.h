#ifndef _GAME_INSTANCE_H
#define	_GAME_INSTANCE_H

#include	"Factory.h"
#include	"FrameLimiter.h"
#include	"KeyController.h"
#include	"InputGUIObject.h"
#include	"Map.h"
#include	"ChangeMapAction.h"
#include	"PlayerMoveAction.h"

class Factory;
class KeyController;

///-------------------------------------------------------------------------------------------------
/// <summary>	The GameInstance class controls the current instance of the game.
/// 			The GameInstance contains all the game assets, as well as
/// 			all maps used by the game. The GameInstance is the
/// 			main game engine object that controls the execution
/// 			of the game. </summary>
///
/// <remarks>	Rosen, 2016-03-04. </remarks>
///-------------------------------------------------------------------------------------------------
class GameInstance
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="window">			[in,out] If non-null, the window. </param>
	/// <param name="renderer">			[in,out] If non-null, the renderer. </param>
	/// <param name="configuration">	The configuration. </param>
	///-------------------------------------------------------------------------------------------------
	GameInstance(SDL_Window* window, SDL_Renderer* renderer, Configuration configuration);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///-------------------------------------------------------------------------------------------------
	~GameInstance();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	bool			initialize();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Runs this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	bool			run();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Exits this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	bool			exit();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Query if this object is initialized. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	true if initialized, false if not. </returns>
	///-------------------------------------------------------------------------------------------------
	bool			isInitialized();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Query if this object is run. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	true if run, false if not. </returns>
	///-------------------------------------------------------------------------------------------------
	bool			isRun();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Query if this object is exited. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	true if exited, false if not. </returns>
	///-------------------------------------------------------------------------------------------------
	bool			isExited();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	null if it fails, else the map. </returns>
	///-------------------------------------------------------------------------------------------------
	Map*			getMap();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="map">	[in,out] If non-null, the map. </param>
	///-------------------------------------------------------------------------------------------------
	void			setMap(Map* map);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets texture asset. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="name">	The name. </param>
	///
	/// <returns>	null if it fails, else the texture asset. </returns>
	///-------------------------------------------------------------------------------------------------
	TextureAsset*		getTextureAsset(std::string name);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a factory. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="factory">	[in,out] If non-null, the factory. </param>
	///-------------------------------------------------------------------------------------------------
	void				setFactory(Factory* factory);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the factory. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	null if it fails, else the factory. </returns>
	///-------------------------------------------------------------------------------------------------
	Factory*			getFactory();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets key controller. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	null if it fails, else the key controller. </returns>
	///-------------------------------------------------------------------------------------------------
	KeyController*		getKeyController();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets key controller. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="keyController">	[in,out] If non-null, the key controller. </param>
	///-------------------------------------------------------------------------------------------------
	void				setKeyController(KeyController* keyController);

	void				setMap(std::string mapName);

private:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Renders the objects. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///-------------------------------------------------------------------------------------------------
	void			renderObjects();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Move objects. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///-------------------------------------------------------------------------------------------------
	void			moveObjects();
	
	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes the actions operation. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///-------------------------------------------------------------------------------------------------
	void			doActions();

	/// <summary>	The configurations. </summary>

	std::map<std::string, Configuration> configurations;

	/// <summary>	The assets. </summary>
	std::map<std::string, Asset*> assets;

	/// <summary>	The texture assets. </summary>
	std::map<std::string, TextureAsset*> textureAssets;

	std::map<std::string, Configuration> maps;

	/// <summary>	The instance window. </summary>
	SDL_Window*		instanceWindow;

	/// <summary>	The instance renderer. </summary>
	SDL_Renderer*	instanceRenderer;

	/// <summary>	The frame limiter. </summary>
	FrameLimiter	frameLimiter;

	/// <summary>	The main configuration. </summary>
	Configuration	mainConfig;

	/// <summary>	true if initialized. </summary>
	bool			initialized;

	/// <summary>	true if runned. </summary>
	bool			runned;

	/// <summary>	true if exited. </summary>
	bool			exited;

	/// <summary>	The map. </summary>
	Map*			map;

	/// <summary>	The factory. </summary>
	Factory*		factory;

	/// <summary>	The key controller. </summary>
	KeyController*	keyController;

	/// <summary>	The frame rate graphical user interface object. </summary>
	GUIObject*		frameRateGUIObject;

	bool			mapChanged;

};

#endif // !_GAME_INSTANCE_H
