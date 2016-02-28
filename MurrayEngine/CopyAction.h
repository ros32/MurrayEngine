#ifndef _COPY_ACTION_H
#define	_COPY_ACTION_H

#include	"Action.h"
#include	"NonPlayerCharacter.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A copy action. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class CopyAction: public Action
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="npc">   	[in,out] If non-null, the npc. </param>
	/// <param name="action">	[in,out] If non-null, the action. </param>
	///-------------------------------------------------------------------------------------------------
	CopyAction(NonPlayerCharacter* npc, Action* action);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	~CopyAction();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Executes this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	void	execute();

private:

};

#endif // !_COPY_ACTION_H
