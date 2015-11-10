#ifndef _FRAME_COUNTER_H
#define	_FRAME_COUNTER_H

//			Max history value for averaging frame rate
#define		FRAME_AVG_HISTORY_SAMPLE			60

#include	<SDL.h>
#include	<vector>
#include	"Timer.h"

class FrameCounter
{
public:
	FrameCounter(Timer timer, int limit);
	~FrameCounter();

	Uint32			getFrames();
	Uint32			getAvgFrames();

	int				getLimit();
	void			setLimit(int limit);

	void			start();
	void			limit();

private:

	int				frameLimit;
	Timer			timer;

	Uint32			frameHistory[FRAME_AVG_HISTORY_SAMPLE];
	unsigned int	nextAvgElement;

};

#endif // !_FRAME_COUNTER_H
