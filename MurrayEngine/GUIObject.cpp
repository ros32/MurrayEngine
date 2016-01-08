#include	"GUIObject.h"

GUIObject::GUIObject()
{
	this->position;
	this->texture;
}

GUIObject::GUIObject(Position pos, TextureAsset* texture)
{
	this->position = pos;
	this->texture = texture;
}

GUIObject::~GUIObject()
{

}

Position	GUIObject::getPosition()
{
	return this->position;
}

TextureAsset*	GUIObject::getTexture()
{
	return this->texture;
}