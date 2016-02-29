#ifndef _GUI_OBSERVABLE_H
#define	_GUI_OBSERVABLE_H

#include	<vector>
#include	"GUIObserver.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A graphical user interface observable. </summary>
///
/// <remarks>	Rosen, 2016-02-29. </remarks>
///-------------------------------------------------------------------------------------------------
class GUIObservable
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///-------------------------------------------------------------------------------------------------
	GUIObservable();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual ~GUIObservable() = 0;

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Attaches the given observer. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///
	/// <param name="observer">	[in,out] If non-null, the observer. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void	attach(GUIObserver* observer);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Detaches the given observer. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///
	/// <param name="observer">	[in,out] If non-null, the observer. </param>
	///-------------------------------------------------------------------------------------------------
	virtual void	detach(GUIObserver* observer);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Notifies this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-29. </remarks>
	///-------------------------------------------------------------------------------------------------
	virtual void	notify() = 0;

private:

	/// <summary>	List of observers. </summary>
	std::vector<GUIObserver*>	observerList;

};

#endif // !_GUI_OBSERVABLE_H
