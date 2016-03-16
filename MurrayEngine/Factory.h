#ifndef _FACTORY_H
#define	_FACTORY_H

#include	"GameInstance.h"
#include	"Map.h"

class GameInstance;
class KeyController;

///-------------------------------------------------------------------------------------------------
/// <summary>	The Factory class contains all factory methods used to create
/// 			objects in the engine. The Factory class is meant to be
/// 			extended by the implementation, but contains default
/// 			implementations of basic functions for testing purposes.</summary>
///
/// <remarks>	Rosen, 2016-03-04. </remarks>
///-------------------------------------------------------------------------------------------------
class Factory
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///-------------------------------------------------------------------------------------------------
	Factory();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~Factory();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Creates a map. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="config">	The configuration. </param>
	///
	/// <returns>	null if it fails, else the new map. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Map*						createMap(Configuration config);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Creates a TextureAsset object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="configuration">	The configuration. </param>
	///
	/// <returns>	null if it fails, else the new asset. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual TextureAsset*				createAsset(Configuration configuration);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Creates a key controller. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="configuration">	The configuration. </param>
	///
	/// <returns>	null if it fails, else the new key controller. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual KeyController*				createKeyController(Configuration configuration);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets game instance. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	null if it fails, else the game instance. </returns>
	///-------------------------------------------------------------------------------------------------
	GameInstance*						getGameInstance();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets game instance. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="instance">	[in,out] If non-null, the instance. </param>
	///-------------------------------------------------------------------------------------------------
	void								setGameInstance(GameInstance* instance);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the window. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <returns>	null if it fails, else the window. </returns>
	///-------------------------------------------------------------------------------------------------
	SDL_Window*							getWindow();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a window. </summary>
	///
	/// <remarks>	Rosen, 2016-03-04. </remarks>
	///
	/// <param name="window">	[in,out] If non-null, the window. </param>
	///-------------------------------------------------------------------------------------------------
	void								setWindow(SDL_Window* window);

//	virtual NonPlayerCharacter* createProjectile(Map* map, Orientation direction, Position pos, Position targetPosition, std::shared_ptr<Animation> animation);

private:

	SDL_Window*			window;
	SDL_Renderer*		renderer;
	GameInstance*		gameInstance;

};


#endif // !_FACTORY_H
