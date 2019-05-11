#include <SDL.h>
#include <stdio.h>
#include "Map.h"
#include "Window.h"
#include "Player.h"
#include "timer.h"
#include "Define.h"
#include "Camara.h"

const int FRAMES_PER_SECOND = 60;

int main(int argc, char *argv[]) {
	Window window("Rainy Platforms", WWIDTH, WHEIGHT/*, "Assets/background.jpg"*/);
	Map map(window, "Assets/tileset.png");
	map.OnLoad("Assets/Maps/1.map");
	Player character(window, 120, 120, 100, 310, "Assets/Idle.png");
	timer FPS;
	Camara camara;

	while (window.running()) {
		FPS.start();
		character.keyboardHandler(FPS);
		window.pollEvents();
		map.OnRender(character.mapX, 0);
		character.draw();
		window.clear();

		if (FPS.get_ticks() < 1000 / FRAMES_PER_SECOND)
			SDL_Delay((1000 / FRAMES_PER_SECOND) - FPS.get_ticks());
	}
	return 0;
}