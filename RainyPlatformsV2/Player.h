#pragma once
#include "Window.h"
#include "timer.h"
#include <string>
#include <iostream>
using namespace std;

class Player : public Window
{
	//The player attributes
	int _width, _height;
	int _x, _y;
	int _r, _g, _b, _a;

	//Jump Related Attributes
	float fallSpeed = -5.0f;
	float forceJump = 5.0f;
	float currentForceJump = 0.0f;
	float gravity = 0.2f;

	//The texture the player will use
	SDL_Texture* _player_texture = nullptr;

	SDL_Rect player = { 0, 0, 0, 0 };

	//Used for Keyboard state (Anti-Ghosting Solution)
	const Uint8* state = SDL_GetKeyboardState(NULL);

	//The bool var that will update depending on the player jump status
	bool isJumping = false;

public:
	Player(const Window &window, int width, int height, int x, int y, const string &image_path);
	~Player();

	void draw();

	/*This function takes to rects and compares
	their x-y values to decide whether they
	are colliding or not.*/
	bool check_collision(SDL_Rect A, SDL_Rect B);

	//Function used for jumping
	void jump(timer& time);

	//Variable used for map positon
	int mapX = 0;

	void keyboardHandler(timer& time);
};