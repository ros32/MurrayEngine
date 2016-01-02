/*
The concrete action MoveAction
Triggers the movements of all movable objects
*/

#ifndef _MOVEACTION_H
#define _MOVEACTION_H

#include "Action.h"
#include "GenericObject.h"
#include "Map.h"
#include <SDL.h>
#include "Camera.h"


class MoveAction : public Action{

public:
	MoveAction(GenericObject* source, Map* map, std::string direction);
	~MoveAction();

	void execute();

private:

	GenericObject* source;
	Map* map;
	std::string direction = "";
};




#endif //!_MOVEACTION_H