#ifndef _NON_PLAYER_CHARACTER_H
#define	_NON_PLAYER_CHARACTER_H

#include	<queue>
#include	"GenericObject.h"
#include	"AI.h"

class NonPlayerCharacter : public GenericObject
{
public:
	NonPlayerCharacter();
	~NonPlayerCharacter();

	virtual void addAction(Action* action);

	virtual void doAction();

private:

	GenericObject*		wrapperObject;
	AI*					ai;

	std::queue<Action*>	actionQueue;

};

#endif // !_NON_PLAYER_CHARACTER_H
