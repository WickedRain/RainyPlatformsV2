#include "Player.h"
#include <SDL_image.h>

Player::Player(const Window &window, int width, int height, int x, int y, const string &image_path):Window(window), _width(width), _height(height), _x(x), _y(y) {
	
	//Auto basically makes the var same type as return type of IMG_LOAD, same as SDL_Surface*
	SDL_Surface* surface = IMG_Load(image_path.c_str()); // <----- Can use auto surface here
	if (!surface)
		cerr << "Failed to create surface! - PLAYER.CPP" << endl;
	_player_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	if (!_player_texture)
		cerr << "Failed to create texture! - PLAYER.CPP" << endl;
	SDL_FreeSurface(surface);
}

void Player::draw()
{
	player = { _x, _y, _width, _height };
	if (_player_texture) {
		SDL_RenderCopy(_renderer, _player_texture, nullptr, &player);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &player);
	}
}

//This Function handles the keyboard states
void Player::keyboardHandler(timer& time) {
	if (state[SDL_SCANCODE_LEFT])
		_x -= 2;
	if (state[SDL_SCANCODE_RIGHT])
		_x += 2;
	if (state[SDL_SCANCODE_SPACE]) {
		jump(time);
	}
}

bool Player::check_collision(SDL_Rect A, SDL_Rect B) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	if (bottomA <= topB)  
		return false; 
	if (topA >= bottomB) 
		return false; 
	if (rightA <= leftB) 
		return false; 
	if (leftA >= rightB) 
		return false;
	return true;
}

void Player::jump(timer& time) {
	if (!isJumping) {
		isJumping = true;
		double deltaTime = time.get_deltaTime();
		currentForceJump = forceJump;
		player.y += currentForceJump * deltaTime;
		
		if (currentForceJump > fallSpeed)
			forceJump -= gravity * deltaTime;
		else
			currentForceJump = fallSpeed;

	}
	else {
		//Player is already jumping
		return;
	}
}

Player::~Player() {
	SDL_DestroyTexture(_player_texture);
	_player_texture = nullptr;
}