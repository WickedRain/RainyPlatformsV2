#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Player.h"

void pollEvents(Window &window/*, Player &rect*/) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		//rect.pollEvents(event);
		window.pollEvents(event);
	}
}

int main(int argc, char *argv[]) {
	Window window("Rainy Platforms", 800, 600);
	Player rect(window, 120, 120, 100, 100, "Assets/Idle (1).png");

	while (window.running()) {
		rect.keyboardHandler();
		pollEvents(window/*, rect*/);
		rect.draw();
		window.clear();
	}
	return 0;
}