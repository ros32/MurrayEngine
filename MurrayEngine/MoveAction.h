/*
The concrete action MoveAction
Triggers the movements of all movable objects
*/

#ifndef _MOVEACTION_H
#define _MOVEACTION_H

#include "Action.h"
#include "Object.h"
#include "Map.h"
#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include "Camera.h"


class MoveAction : public Action{

public:
	MoveAction(Object* source, Map* map, std::string direction);
	MoveAction(Object* source, Map* map, std::string direction, int repeat);
	~MoveAction();

	void execute();

	Action*	copy();

private:

	int repeat;
	int currentRepeat;
	Object* source;
	Map* map;
	std::string direction = "";
};




#endif //!_MOVEACTION_H