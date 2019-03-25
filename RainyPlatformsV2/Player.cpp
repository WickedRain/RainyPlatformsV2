#include "Player.h"
#include <SDL_image.h>

Player::Player(const Window &window, int width, int height, int x, int y, const string &image_path):Window(window), _width(width), _height(height), _x(x), _y(y) {
	
	//auto basically makes the var same type as return type of IMG_LOAD, same as SDL_Surface*
	SDL_Surface* surface = IMG_Load(image_path.c_str()); // <----- Can use auto surface here
	if (!surface)
		cerr << "Failed to create surface!" << endl;
	_player_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	if (!_player_texture)
		cerr << "Failed to create texture!" << endl;
	SDL_FreeSurface(surface);
}

void Player::draw()const
{
	SDL_Rect Player = { _x, _y, _width, _height };
	if (_player_texture) {
		SDL_RenderCopy(_renderer, _player_texture, nullptr, &Player);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &Player);
	}
}

void Player::pollEvents(SDL_Event &event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_w:
			_y -= 2;
			break;
		case SDLK_a:
			_x -= 2;
			break;
		case SDLK_s:
			_y += 2;
			break;
		case SDLK_d:
			_x += 2;
			break;
		}
	}
}

Player::~Player() {
	SDL_DestroyTexture(_player_texture);
	_player_texture = nullptr;
}