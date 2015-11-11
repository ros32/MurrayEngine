#include	"FrameLimiter.h"



FrameLimiter::FrameLimiter(Timer timer, int limit)
{
	this->timer = timer;
	this->frameLimit = limit;
	this->nextAvgElement = 0;

	Uint32	bootstrapAvgCounter = this->timer.getTicks();
	for (int i = 0; i < FRAME_AVG_HISTORY_SAMPLE; i++)
	{
		this->frameHistory[i] = bootstrapAvgCounter;
	}
}

FrameLimiter::~FrameLimiter()
{
	this->timer.stop();
}

Uint32	FrameLimiter::getAvgFrames()
{
	Uint32	avgFrames = 0;
	for (Uint32 frame : this->frameHistory)
	{
		avgFrames += frame;
	}

	return avgFrames/FRAME_AVG_HISTORY_SAMPLE;
}

void FrameLimiter::start()
{
	this->timer.start();
}

void FrameLimiter::limit()
{
	//	Get current frame processing time
	Uint32	frameTime = this->timer.getTicks();

	//	Declare and set extra delay to frame to 0
	Uint32	frameDelay = 0;

	//	Find next element in history array, if over limit reset
	if (++this->nextAvgElement >= FRAME_AVG_HISTORY_SAMPLE)
		this->nextAvgElement = 0;

	//	Enter new value in average history
	this->frameHistory[this->nextAvgElement] = frameTime;


	//	Set delay to the difference between (frame limit) max processing time
	//	and average frame processing time
	frameDelay = (1000 / this->frameLimit) - this->getAvgFrames();

	//	If frame delay is within reasonable value (we perform subtraction on unsigned integers):
	//	Delay frame processing specified amount
	if (frameDelay > 0 && frameDelay < 1000)
		SDL_Delay(frameDelay);
}