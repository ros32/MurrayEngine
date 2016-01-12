#ifndef _NON_PLAYER_CHARACTER_H
#define	_NON_PLAYER_CHARACTER_H

#include	"GenericObject.h"

class NonPlayerCharacter : public GenericObject
{
public:
	NonPlayerCharacter();
	~NonPlayerCharacter();

private:

	GenericObject*		wrapperObject;


};

#endif // !_NON_PLAYER_CHARACTER_H
