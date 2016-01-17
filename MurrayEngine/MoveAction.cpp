#include "MoveAction.h"

MoveAction::MoveAction(Object* source, Map* map, std::string direction){
	this->source = source;
	this->map = map;
	this->direction = direction;
}
MoveAction::~MoveAction(){

}
void MoveAction::execute()
{

	/*
	if (source == map->getPlayerCharacter()){
	SDL_Log("You are moving the player character");
	}
	else if (source != map->getPlayerCharacter()){
	SDL_Log("Something else is moving");
	}

	*/



	if (direction == "EAST")
	{
		source->setTargetPosition(source->getTargetPosition().x + source->getCurrentSpeed(), source->getTargetPosition().y);
		source->setOrientation(EAST);
		//Call appropriate animation

	}

	if (direction == "WEST")
	{

		source->setTargetPosition(source->getTargetPosition().x - source->getCurrentSpeed(), source->getTargetPosition().y);
		source->setOrientation(WEST);
		//Call appropriate animation
	}

	if (direction == "NORTH")
	{

		source->setTargetPosition(source->getTargetPosition().x, source->getTargetPosition().y - source->getCurrentSpeed());
		source->setOrientation(NORTH);
		//Call appropriate animation
	}

	if (direction == "SOUTH")
	{

		source->setTargetPosition(source->getTargetPosition().x, source->getTargetPosition().y + source->getCurrentSpeed());
		source->setOrientation(SOUTH);
		//Call appropriate animation
	}
}