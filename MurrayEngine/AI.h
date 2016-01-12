#ifndef _AI_H
#define	_AI_H

#include	<vector>
#include	"NonPlayerCharacter.h"
#include	"GameInstance.h"

class AI
{
public:
	AI();
	~AI();

	void	doNext();
	void	cancel();

	void	attack();
	void	flee();

	void	patrol();





private:

};

#endif // !_AI_HJ
