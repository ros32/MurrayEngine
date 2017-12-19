#ifndef _INPUT_GUI_OBJECT
#define	_INPUT_GUI_OBJECT

#include	"GUIObject.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	The InputGUIObject class is an extension of the GUIObject that allows input of text. </summary>
///
/// <remarks>	Rosen, 2016-03-17. </remarks>
///-------------------------------------------------------------------------------------------------
class InputGUIObject: public GUIObject
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="renderer">	[in,out] If non-null, the renderer. </param>
	/// <param name="pos">	   	The position. </param>
	///-------------------------------------------------------------------------------------------------
	InputGUIObject(SDL_Renderer* renderer, Position pos);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	~InputGUIObject();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the texture. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	null if it fails, else the texture. </returns>
	///-------------------------------------------------------------------------------------------------
	TextureAsset*	getTexture() override;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Adds a character. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="c">	The character. </param>
	///-------------------------------------------------------------------------------------------------
	void			addChar(char c);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Removes the character. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void			removeChar();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Query if this object is visible. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	true if visible, false if not. </returns>
	///-------------------------------------------------------------------------------------------------
	bool			isVisible() = delete;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a visible. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <param name="visible">	true to show, false to hide. </param>
	///-------------------------------------------------------------------------------------------------
	void			setVisible(bool visible) = delete;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the text. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///
	/// <returns>	The text. </returns>
	///-------------------------------------------------------------------------------------------------
	std::string		getText();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Clears the text. </summary>
	///
	/// <remarks>	Rosen, 2016-03-17. </remarks>
	///-------------------------------------------------------------------------------------------------
	void			clearText();

private:

	/// <summary>	The renderer. </summary>
	SDL_Renderer*	renderer;
	/// <summary>	The text. </summary>
	std::string		text;
	/// <summary>	true to show, false to hide. </summary>
	bool			visible;

};

#endif // !_INPUT_GUI_OBJECT
