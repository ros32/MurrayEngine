#ifndef _GUI_H
#define	_GUI_H

#include	<vector>
#include	<algorithm>
#include	"GUIObject.h"
#include	"InputGUIObject.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A graphical user interface. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class GUI
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	GUI(SDL_Renderer* renderer);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	~GUI();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets graphical user interface objects. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	null if it fails, else the graphical user interface objects. </returns>
	///-------------------------------------------------------------------------------------------------
	std::vector<GUIObject*>	getGUIObjects();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Adds an object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="object">	[in,out] If non-null, the object. </param>
	///-------------------------------------------------------------------------------------------------
	void	addObject(GUIObject* object);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Removes the object described by object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="object">	[in,out] If non-null, the object. </param>
	///-------------------------------------------------------------------------------------------------
	void	removeObject(GUIObject* object);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Renders this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	void	render();

	InputGUIObject*		getInputObject();

private:

	/// <summary>	The graphical user interface objects. </summary>
	std::vector<GUIObject*>		guiObjects;

	InputGUIObject*	inputGUIObject;

};

#endif // !_GUI_H
