#ifndef _INPUT_GUI_OBJECT
#define	_INPUT_GUI_OBJECT

#include	"GUIObject.h"

class InputGUIObject: public GUIObject
{
public:
	InputGUIObject(SDL_Renderer* renderer, Position pos);
	~InputGUIObject();

	TextureAsset*	getTexture();

	void			addChar(char c);
	void			removeChar();

	bool			isVisible();
	void			setVisible(bool visible);

	std::string		getText();

	void			clearText();

private:

	SDL_Renderer*	renderer;
	std::string		text;
	bool			visible;

};

#endif // !_INPUT_GUI_OBJECT
