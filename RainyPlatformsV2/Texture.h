#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Player.h"
using namespace std;

class Texture //: public Window
{
	//The actual hardware texture
	SDL_Texture* _Texture;

	//Image dimensions
	int _Width;
	int _Height;
public:
	Texture();
	~Texture();

	//Loads image at specified path
	bool loadFromFile(string path);

	//Deallocates texture
	void free();

	//Renders the texture at a given point
	void render(int x, int y);

	//Gets the image dimensions
	int getWidth();
	int getHeight();
};

