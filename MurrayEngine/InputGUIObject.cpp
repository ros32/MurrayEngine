#include	"InputGUIObject.h"

InputGUIObject::InputGUIObject(SDL_Renderer* renderer, Position pos) : GUIObject()
{
	this->setPosition(pos);
	this->setTexture(nullptr);
	this->renderer = renderer;
	this->visible = true;
	this->text = "";

}

InputGUIObject::~InputGUIObject()
{

}

void	InputGUIObject::addChar(char c)
{
	this->text += c;
	delete this->getTexture();
	this->setTexture(new TextureAsset(this->renderer, "8bitOperatorPlusSC-Bold.ttf", 24, this->text, { 240, 240, 240 }));
}

void	InputGUIObject::removeChar()
{
	this->text = this->text.substr(0, this->text.size() - 1);
	delete this->getTexture();
	this->setTexture(new TextureAsset(this->renderer, "8bitOperatorPlusSC-Bold.ttf", 24, this->text, { 240, 240, 240 }));
}

TextureAsset*	InputGUIObject::getTexture()
{
	if (this->visible)
		return GUIObject::getTexture();
	return nullptr;
}

std::string		InputGUIObject::getText()
{
	return this->text;
}

void			InputGUIObject::clearText()
{
	this->text = "";
	delete this->getTexture();
	this->setTexture(nullptr);
}