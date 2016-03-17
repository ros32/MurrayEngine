#include	"FrameLimiter.h"

FrameLimiter::FrameLimiter() : FrameLimiter(Timer(), 30) { }

FrameLimiter::FrameLimiter(Timer timer, int limit)
{
	this->timer = timer;
	this->frameLimit = limit;
}

FrameLimiter::~FrameLimiter()
{
	this->timer.stop();
}

void FrameLimiter::start()
{
	this->timer.start();
}

void FrameLimiter::limit()
{
	if (this->frameLimit > 0)
	{
	//	Get current frame processing time
		Uint32	elapsedTime = this->timer.getTicks();

		Uint32	minTime = 1000 / this->frameLimit;

		if (elapsedTime < minTime)
		{
			SDL_Delay((minTime - elapsedTime));
		}

	}
}