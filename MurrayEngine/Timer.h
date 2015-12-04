#ifndef _TIMER_H
#define	_TIMER_H

#include <SDL.h>

class Timer
{
public:
	Timer();
	~Timer();

	void		start();
	void		pause();
	void		unpause();
	void		stop();

	bool		isPaused();
	bool		isStarted();

	Uint32		getTicks();

private:

	Uint32		startTicks;
	Uint32		pausedTicks;

	bool		paused;
	bool		started;

};

#endif // !_TIMER_H
