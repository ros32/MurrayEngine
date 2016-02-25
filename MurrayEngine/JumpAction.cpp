#include "JumpAction.h"

JumpAction::JumpAction(Map* map, Object* source, Orientation orientation){
	this->source = source;
	this->map = map;
	this->orientation = orientation;
	this->tempVector;
	this->tempTime;
}
JumpAction::~JumpAction(){

}
void JumpAction::execute(){

	Position startPos;
	Position targetPos;

	if (orientation == NORTH){
		startPos = {source->getCurrentPosition().x, source->getCurrentPosition().y - source->getTexture()->asset->getHeight()};
		targetPos = { startPos.x, startPos.y - source->getCurrentSpeed() };
	}
	if (orientation == SOUTH){
		startPos = { source->getCurrentPosition().x, source->getCurrentPosition().y + source->getTexture()->asset->getHeight() };
		targetPos = { startPos.x, startPos.y + source->getCurrentSpeed() };
	}
	if (orientation == WEST){
		startPos = { source->getCurrentPosition().x - source->getTexture()->asset->getWidth(), source->getCurrentPosition().y };
		targetPos = { startPos.x - source->getCurrentSpeed(), startPos.y };
	}
	if (orientation == EAST){
		startPos = { source->getCurrentPosition().x + source->getTexture()->asset->getWidth(), source->getCurrentPosition().y};
		targetPos = { startPos.x + source->getCurrentSpeed(), startPos.y };
	}
	


}

Action* JumpAction::copy(){
	return new JumpAction(this-> map, this->source, this->orientation);
}

