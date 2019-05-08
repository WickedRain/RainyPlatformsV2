#pragma once
#include <string>
#include <SDL.h>
using namespace std;

class Window
{
	//Initilization Method
	bool init();

	//Window Properties
	string _title;
	int _width;
	int _height;

	//Checks if window is closed or not
	bool isRunning = true;

	//Creates window and sets to null
	SDL_Window *_window = nullptr;

	//Creates background texture
	SDL_Texture* _background_texture = nullptr;

	string _image_path;
protected:
	SDL_Renderer *_renderer = nullptr;

public:

	Window(const string &title, int width, int height/*, const string &image_path*/);
	~Window();

	inline bool running()const { return isRunning; }
	void pollEvents();
	void clear() const;
};

