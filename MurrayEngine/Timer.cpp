#define _CRTDBG_MAP_ALLOC
#include	"Timer.h"

Timer::Timer()
{
	this->started = false;
	this->paused = false;

	this->startTicks = 0;
	this->pausedTicks = 0;
}

Timer::~Timer()
{
	this->stop();
}

void Timer::start()
{
	this->started = true;

	this->startTicks = SDL_GetTicks();
}

void	Timer::pause()
{
	this->paused = true;
	this->pausedTicks = this->startTicks - SDL_GetTicks();
}

void	Timer::unpause()
{
	this->paused = false;
	this->pausedTicks = 0;
}

void	Timer::stop()
{
	this->started = false;
	this->startTicks = 0;
}

bool	Timer::isStarted()
{
	return this->started;
}

bool	Timer::isPaused()
{
	return this->paused;
}

Uint32	Timer::getTicks()
{
	if (this->started && !this->paused)
		return SDL_GetTicks() - this->startTicks;
	if (this->started && this->paused)
		return this->pausedTicks;
	else
		return 0;
}

