#ifndef _KEY_CONTROLLER_H
#define	_KEY_CONTROLLER_H

#include	<map>
#include	"GameInstance.h"
#include	"ChangeInputModeAction.h"
#include	"Object.h"

class GameInstance;

///-------------------------------------------------------------------------------------------------
/// <summary>	The KeyController handles key input.
/// 			
/// 			Keys can be bound to Actions, using addAction() </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class KeyController
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	KeyController();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~KeyController();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Check state. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void	checkState();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Binds an Action to a key. 
	/// 			
	/// 			If repeat is enabled, holding down the key will
	/// 			cause the action to be launched multiple times, whereas false will causing an
	/// 			action to only be executed once each keypress. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="key">   	The key. </param>
	/// <param name="action">	[in,out] If non-null, the action. </param>
	/// <param name="repeat">	true to repeat. </param>
	///-------------------------------------------------------------------------------------------------
	void	addAction(SDL_Scancode key, Action* action, bool repeat);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets game instance. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="instance">	[in,out] If non-null, the instance. </param>
	///-------------------------------------------------------------------------------------------------
	void	setGameInstance(GameInstance* instance);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets text input mode. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="inputMode">	true to enable input mode, false to disable it. </param>
	///-------------------------------------------------------------------------------------------------
	void	setTextInputMode(bool inputMode);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets text input mode. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	///-------------------------------------------------------------------------------------------------
	bool	getTextInputMode();

private:

	/// <summary>	The game instance. </summary>
	GameInstance*					gameInstance;

	/// <summary>	The keys. </summary>
	std::map< SDL_Scancode, bool >	keys;
	/// <summary>	The characters. </summary>
	std::map< SDL_Scancode, char >	chars;
	/// <summary>	The last status. </summary>
	std::map< SDL_Scancode, bool >	lastStatus;
	/// <summary>	The repeat. </summary>
	std::map< SDL_Scancode, bool >	repeat;
	/// <summary>	The actions. </summary>
	std::map< SDL_Scancode, Action* >	actions;

	/// <summary>	true to enable text input mode, false to disable it. </summary>
	bool	textInputMode;



};

#endif
