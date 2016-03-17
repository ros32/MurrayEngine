#ifndef _CHANGE_INPUT_MODE_ACTION_H
#define	_CHANGE_INPUT_MODE_ACTION_H

#include	"Action.h"
#include	"KeyController.h"

class KeyController;

///-------------------------------------------------------------------------------------------------
/// <summary>	The ChangeInputModeAction class is an Action used to change keyboard input mode
/// 			between game and text.
/// 			
/// 			When executed, the keyboard input mode will change between game (keys control game) and
/// 			text (keys typed in an InputGUIObject). </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class ChangeInputModeAction: public Action
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="keyController">	[in,out] If non-null, the key controller. </param>
	///-------------------------------------------------------------------------------------------------
	ChangeInputModeAction(KeyController* keyController);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~ChangeInputModeAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void	execute();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Copies this object. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else an Action*. </returns>
	///-------------------------------------------------------------------------------------------------
	Action*	copy();

private:

	/// <summary>	The key controller. </summary>
	KeyController* keyController;

};

#endif // !_CHANGE_INPUT_MODE_ACTION_H
