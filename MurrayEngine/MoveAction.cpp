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

	if (direction == "EAST")
	{
		source->setTargetPosition(source->getTargetPosition().x + source->getCurrentSpeed(), source->getTargetPosition().y);

		if (source->getOrientation() != EAST)
			source->changeAnimation("East");
		
		source->setOrientation(EAST);
		

	}

	if (direction == "WEST")
	{

		source->setTargetPosition(source->getTargetPosition().x - source->getCurrentSpeed(), source->getTargetPosition().y);
		if (source->getOrientation() != WEST)
			source->changeAnimation("West");

		source->setOrientation(WEST);
		
		
	}

	if (direction == "NORTH")
	{

		source->setTargetPosition(source->getTargetPosition().x, source->getTargetPosition().y - source->getCurrentSpeed());
		
		if (source->getOrientation() != NORTH)
			source->changeAnimation("North");
				
		source->setOrientation(NORTH);
	
	}

	if (direction == "SOUTH")
	{

		source->setTargetPosition(source->getTargetPosition().x, source->getTargetPosition().y + source->getCurrentSpeed());

		if (source->getOrientation() != SOUTH)
			source->changeAnimation("South");
		

		source->setOrientation(SOUTH);

	}
}