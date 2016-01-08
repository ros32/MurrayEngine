#ifndef _GUI_OBJECT_H
#define	_GUI_OBJECT_H

#include	"Position.h"
#include	"TextureAsset.h"

class GUIObject
{
public:
	GUIObject();
	GUIObject(Position pos, TextureAsset* texture);
	~GUIObject();

	Position		getPosition();
	TextureAsset*	getTexture();

	void			setPosition(Position pos);
	void			setTexture(TextureAsset* texture);

private:

	Position position;
	TextureAsset* texture;

};

#endif // !_GUI_OBJECT_H
