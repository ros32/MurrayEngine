#include "MoveAction.h"

MoveAction::MoveAction(GenericObject* source, Map* map, std::string direction){
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
		if (map->getCamera() != nullptr)
		{
			SDL_Log("Inside MoveAction-Execute");
			if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
				this->map->getCamera()->move(5, 0);
			else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
				this->map->getPlayerCharacter()->setTargetPosition(this->map->getPlayerCharacter()->getTargetPosition().x + this->map->getPlayerCharacter()->getCurrentSpeed(), this->map->getPlayerCharacter()->getTargetPosition().y + 0);
			this->map->getPlayerCharacter()->setOrientation(EAST);
		}
	}

	if (direction == "WEST")
	{
		if (this->map->getCamera() != nullptr)
		{
			if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
				this->map->getCamera()->move(-5, 0);
			else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
				this->map->getPlayerCharacter()->setTargetPosition(this->map->getPlayerCharacter()->getTargetPosition().x - this->map->getPlayerCharacter()->getCurrentSpeed(), this->map->getPlayerCharacter()->getTargetPosition().y + 0);
			this->map->getPlayerCharacter()->setOrientation(WEST);
		}
	}

	if (direction == "NORTH")
	{
		if (this->map->getCamera() != nullptr)
		{
			if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
				this->map->getCamera()->move(0, -5);
			else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
				this->map->getPlayerCharacter()->setTargetPosition(this->map->getPlayerCharacter()->getTargetPosition().x + 0, this->map->getPlayerCharacter()->getTargetPosition().y - this->map->getPlayerCharacter()->getCurrentSpeed());
			this->map->getPlayerCharacter()->setOrientation(NORTH);
		}
	}

	if (direction == "SOUTH")
	{
		if (this->map->getCamera() != nullptr)
		{
			if (this->map->getCamera()->getFocusType() == FREE_FOCUS)
				this->map->getCamera()->move(0, 5);
			else if (this->map->getCamera()->getFocusType() == OBJECT_FOCUS)
				this->map->getPlayerCharacter()->setTargetPosition(this->map->getPlayerCharacter()->getTargetPosition().x + 0, this->map->getPlayerCharacter()->getTargetPosition().y + this->map->getPlayerCharacter()->getCurrentSpeed());
			this->map->getPlayerCharacter()->setOrientation(SOUTH);
		}

	}
}