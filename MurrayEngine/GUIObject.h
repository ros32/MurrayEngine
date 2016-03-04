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

	virtual Position		getPosition();
	virtual TextureAsset*	getTexture();

	virtual void	setPosition(Position pos);
	virtual void	setTexture(TextureAsset* texture);

private:

	Position position;
	TextureAsset* texture;

};

#endif // !_GUI_OBJECT_H
