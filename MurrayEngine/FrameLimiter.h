#ifndef _FRAME_LIMITER_H
#define	_FRAME_LIMITER_H

//			Define the frame rate history sample size.
//				By limiting frame rate based on average frame rate,
//				we get a smoother transition between normal operation (with added delay)
//				and process intensive tasks (where the main loop takes longer than the limit
//				to execute.
#define		FRAME_AVG_HISTORY_SAMPLE			2

#ifdef _WIN32
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#endif
#include	<vector>
#include	"Timer.h"

///	<summary>
///	The Frame Limiter class controls the processing speed of a main loop, 
///	and ensures that each pass of the loop runs for at least n/1000 ms
///	(n = frames per second).
///	</summary>
class FrameLimiter
{
public:

	///	<summary>
	///	Create a new FrameLimiter with default values
	///	</summary>
	FrameLimiter();

	///	<summary>
	///	Create a new FrameLimiter with a copy of the provided Timer
	///	and the specified frame limit
	///	</summary>
	FrameLimiter(Timer timer, int limit);


	~FrameLimiter();

	///	<summary>
	///	Return the average frame rate. Size of sample is determined by
	///	the macro FRAME_AVG_HISTORY_SAMPLE
	///	</summary>
	Uint32			getAvgFrames();

	///	<summary>
	///	Return the frame limit
	///	</summary>
	int				getLimit();

	///	<summary>
	///	Set the frame limit to the specified value
	///	</summary>
	void			setLimit(int limit);

	///	<summary>
	///	Start the frame limiter and begin to measure time
	///	</summary>
	void			start();

	///	<summary>
	///	Calculate average frame time and execute delay
	///	</summary>
	void			limit();

private:

	int				frameLimit;
	Timer			timer;

	Uint32			frameHistory[FRAME_AVG_HISTORY_SAMPLE];
	unsigned int	nextAvgElement;

};

#endif // !_FRAME_LIMITER_H