#ifndef _FRAME_LIMITER_H
#define	_FRAME_LIMITER_H

///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines frame average history sample. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
#define		FRAME_AVG_HISTORY_SAMPLE			2

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include	<vector>
#include	"Timer.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	A frame limiter. </summary>
///
/// <remarks>	Rosen, 2016-02-28. </remarks>
///-------------------------------------------------------------------------------------------------
class FrameLimiter
{
public:

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	FrameLimiter();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Constructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="timer">	The timer. </param>
	/// <param name="limit">	The limit. </param>
	///-------------------------------------------------------------------------------------------------
	FrameLimiter(Timer timer, int limit);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	~FrameLimiter();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets average frames. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The average frames. </returns>
	///-------------------------------------------------------------------------------------------------
	Uint32			getAvgFrames();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Gets the limit. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <returns>	The limit. </returns>
	///-------------------------------------------------------------------------------------------------
	int				getLimit();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Sets a limit. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///
	/// <param name="limit">	The limit. </param>
	///-------------------------------------------------------------------------------------------------
	void			setLimit(int limit);

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Starts this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	void			start();

	///-------------------------------------------------------------------------------------------------
	/// <summary>	Limits this object. </summary>
	///
	/// <remarks>	Rosen, 2016-02-28. </remarks>
	///-------------------------------------------------------------------------------------------------
	void			limit();

private:

	/// <summary>	The frame limit. </summary>
	int				frameLimit;

	/// <summary>	The timer. </summary>
	Timer			timer;

	/// <summary>	The frame history[ frame average history sample]. </summary>
	Uint32			frameHistory[FRAME_AVG_HISTORY_SAMPLE];

	/// <summary>	The next average element. </summary>
	unsigned int	nextAvgElement;

};

#endif // !_FRAME_LIMITER_H