#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Player.h"
#include "timer.h"

const int FRAMES_PER_SECOND = 60; 

int main(int argc, char *argv[]) {
	Window window("Rainy Platforms", 800, 600, "Assets/background.jpg");
	Player character(window, 120, 120, 100, 100, "Assets/Idle (1).png");
	timer FPS;

	while (window.running()) {
		FPS.start();
		character.keyboardHandler(FPS);
		window.pollEvents();
		character.draw();
		window.clear();

		if (FPS.get_ticks() < 1000 / FRAMES_PER_SECOND) 
			SDL_Delay((1000 / FRAMES_PER_SECOND) - FPS.get_ticks());
	}
	return 0;
}