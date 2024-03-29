#include "Timer.h"

Timer::Timer()
{
	resetted = true;
	running = false;
	beginning = 0;
	end = 0;
}

void Timer::start()
{
	if (!running)
	{
		if (resetted)
			beginning = (unsigned long)clock();
		else
			beginning -= end - (unsigned long)clock();
		running = true;
		resetted = false;
	}
}

void Timer::stop()
{
	if (running)
	{
		end = (unsigned long)clock();
		running = false;
	}
}

void Timer::reset()
{
	bool wereRunning = running;
	if (wereRunning)
		stop();
	resetted = true;
	beginning = 0;
	end = 0;
	if (wereRunning)
		start();
}

bool Timer::isRunning() {
	return running;
}

unsigned long Timer::getTime() {
	if (running)
		return ((unsigned long)clock() - beginning) / CLOCKS_PER_SEC;
	else
		return end - beginning;
}

bool Timer::isOver(unsigned long seconds) {
	return seconds >= getTime();
}