#ifndef _CHANGE_MAP_ACTION
#define	_CHANGE_MAP_ACTION

#include	<string>
#include	"Action.h"
#include	"GameInstance.h"

class ChangeMapAction: public Action
{
public:
	ChangeMapAction(GameInstance* gameInstance, std::string mapName);
	~ChangeMapAction();

	void execute();
	Action* copy();

private:

	GameInstance*	gameInstance;
	std::string		mapName;

};

#endif // !_CHANGE_MAP_ACTION
