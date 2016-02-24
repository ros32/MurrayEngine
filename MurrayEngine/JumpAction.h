/*
The concrete action JumpAction
*/

#ifndef _JUMPACTION_H
#define _JUMPACTION_H

#include "Object.h"
#include "Action.h"
#include "AnimatedObject.h"
#include "ProjectileObject.h"
#include <vector>
#include "Map.h"

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif

//class GameInstance;
class Map;

class JumpAction : public Action{

public:
	JumpAction(Map* map, Object* source, Orientation orientation);
	~JumpAction();

	void execute();

	Action* copy();

private:

	Object* source;
	Orientation orientation;
//	GameInstance* instance;
	Map* map;
	std::vector<Texture> tempVector;
	int tempTime;
	

};



#endif //!_JUMPACTION_H