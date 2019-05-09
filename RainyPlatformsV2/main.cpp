#include <SDL.h>
#include <stdio.h>
#include "Map.h"
#include "Window.h"
#include "Player.h"
#include "timer.h"
#include "Define.h"
#include "Camara.h"

const int FRAMES_PER_SECOND = 60;

const Uint8* state = SDL_GetKeyboardState(NULL);
void keyboardHandler(Camara camara);

int main(int argc, char *argv[]) {
	Window window("Rainy Platforms", WWIDTH, WHEIGHT/*, "Assets/background.jpg"*/);
	Map map(window, "Assets/tileset.png");
	map.OnLoad("Assets/Maps/1.map");
	Player character(window, 120, 120, 100, 100, "Assets/Idle.png");
	timer FPS;
	Camara camara;

	while (window.running()) {
		FPS.start();
		character.keyboardHandler(FPS);
		window.pollEvents();
		map.OnRender(0, 0);
		keyboardHandler(camara);
		character.draw();
		window.clear();

		if (FPS.get_ticks() < 1000 / FRAMES_PER_SECOND)
			SDL_Delay((1000 / FRAMES_PER_SECOND) - FPS.get_ticks());
	}
	return 0;
}

void keyboardHandler(Camara camara)
{
	{
		if (state[SDL_SCANCODE_LEFT])
			camara.CamaraControl.OnMove(5, 0);
		if (state[SDL_SCANCODE_RIGHT])
			camara.CamaraControl.OnMove(-5, 0);
		if (state[SDL_SCANCODE_UP])
			camara.CamaraControl.OnMove(0, 5);
		if (state[SDL_SCANCODE_DOWN])
			camara.CamaraControl.OnMove(0, -5);
	}
}
