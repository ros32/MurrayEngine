#ifndef _FRAME_LIMITER_H
#define	_FRAME_LIMITER_H

//			Max history value for averaging frame rate
#define		FRAME_AVG_HISTORY_SAMPLE			2

#include	<SDL.h>
#include	<vector>
#include	"Timer.h"

class FrameLimiter
{
public:
	FrameLimiter(Timer timer, int limit);
	~FrameLimiter();

	//	Return average frame rate
	Uint32			getAvgFrames();

	//	Return frame limit
	int				getLimit();

	//	Set frame limit
	void			setLimit(int limit);

	//	Start frame limiter
	void			start();

	//	Calculate delay
	void			limit();

private:

	int				frameLimit;
	Timer			timer;

	Uint32			frameHistory[FRAME_AVG_HISTORY_SAMPLE];
	unsigned int	nextAvgElement;

};

#endif // !_FRAME_LIMITER_H