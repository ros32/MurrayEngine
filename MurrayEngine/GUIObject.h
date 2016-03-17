#ifndef _GUI_OBJECT_H
#define	_GUI_OBJECT_H

#include	"Position.h"
#include	"TextureAsset.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A GUIObject is an object displayed in the GUI. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class GUIObject
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	GUIObject();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="pos">	  	The position. </param>
	/// <param name="texture">	[in,out] If non-null, the texture. </param>
	///-------------------------------------------------------------------------------------------------
	GUIObject(Position pos, TextureAsset* texture);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~GUIObject();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The position. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual Position		getPosition();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the texture. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else the texture. </returns>
	///-------------------------------------------------------------------------------------------------
	virtual TextureAsset*	getTexture();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a position. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="pos">	The position. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void	setPosition(Position pos);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a texture. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="texture">	[in,out] If non-null, the texture. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void	setTexture(TextureAsset* texture);

private:

	/// <summary>	The position. </summary>
	Position position;
	/// <summary>	The texture. </summary>
	TextureAsset* texture;

};

#endif // !_GUI_OBJECT_H
