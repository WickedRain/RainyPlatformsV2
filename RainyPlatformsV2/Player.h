#pragma once
#include "Window.h"
#include <string>
#include <iostream>
using namespace std;

class Player :public Window
{
	int _width, _height;
	int _x, _y;
	int _r, _g, _b, _a;
	SDL_Texture* _player_texture = nullptr;

public:
	Player(const Window &window, int width, int height, int x, int y, const string &image_path);
	~Player();

	void draw()const;
	void pollEvents(SDL_Event &event);
};

