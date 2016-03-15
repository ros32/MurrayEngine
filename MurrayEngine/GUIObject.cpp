#include	"GUIObject.h"

GUIObject::GUIObject()
{
	this->position = { 0, 0 };
	this->texture = nullptr;
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

void		GUIObject::setTexture(TextureAsset* texture)
{
	this->texture = texture;
}

TextureAsset*	GUIObject::getTexture()
{
	return this->texture;
}

void		GUIObject::setPosition(Position pos)
{
	this->position = pos;
}