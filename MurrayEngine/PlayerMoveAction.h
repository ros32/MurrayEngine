#ifndef _PLAYER_MOVE_ACTION_H
#define	_PLAYER_MOVE_ACTION_H

#include	<string>
#include	"GameInstance.h"
#include	"Action.h"

class PlayerMoveAction: public Action
{
public:
	PlayerMoveAction(std::string id, GameInstance* gameInstance, Orientation direction);
	PlayerMoveAction(std::string id, GameInstance* gameInstance, Orientation direction, int repeat);
	~PlayerMoveAction();

	void	execute();
	Action*	copy();

private:

	std::string		source;
	GameInstance*	gameInstance;
	Orientation		direction;

	int repeat;
	int currentRepeat;


};

#endif // !_PLAYER_MOVE_ACTION_H
