#include "timer.h"



timer::timer(){
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void timer::start() {
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}
void timer::stop() {
	started = false;
	paused = false;
}
void timer::pause() {
	if ((started == true) && (paused == false)) {
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}
void timer::unpause() {
	if (paused == true) {
		paused = false;
		startTicks = SDL_GetTicks() - pausedTicks;
		pausedTicks = 0;
	}
}
int timer::get_ticks() {
	if (started == true) {
		if (paused == true)
			return pausedTicks;
		else
			return SDL_GetTicks() - startTicks;
	}
	return 0;
}

int timer::get_deltaTime() {
	Uint64 currentFrame = SDL_GetPerformanceCounter();
	Uint64 prevFrame = 0;
	double deltaTime = 0;

	while (is_started())
	{
		prevFrame = currentFrame;
		currentFrame = SDL_GetPerformanceCounter();

		deltaTime = (double)((currentFrame - prevFrame) * 1000 / (double)SDL_GetPerformanceFrequency());
		return deltaTime;
	}
	return 0;
}

