#include "MoveAction.h"

MoveAction::MoveAction(Object* source, Map* map, std::string direction){
	this->source = source;
	this->map = map;
	this->direction = direction;
	this->repeat = -1;
	this->currentRepeat = 1;
}

MoveAction::MoveAction(Object* source, Map* map, std::string direction, int repeat)
{
	this->source = source;
	this->map = map;
	this->direction = direction;
	this->repeat = repeat;
	this->currentRepeat = repeat;

}
MoveAction::~MoveAction(){

}
void MoveAction::execute()
{
	if (this->currentRepeat > 0 || repeat == -1)
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

		if (this->repeat != -1)
			this->updateProgress((float)1 / (float)this->currentRepeat);
		currentRepeat--;
	}

	if (currentRepeat == 0)
		this->setProgress(1);


}

Action*	MoveAction::copy()
{
	return new MoveAction(this->source, this->map, this->direction);
}