#ifndef GAME_H
#define GAME_H

#if defined __linux__
#include <SDL2/SDL.h>
#elif defined _WIN32
#include <SDL.h>
#endif

#include <vector>

class Platform;
class Ball;

class Game
{
	SDL_Window* gameWindow;
	SDL_Renderer* gameRenderer;
	SDL_Event gameEvent;

	std::vector<Platform*> platforms;
	Ball* ball;
	
	bool done;
	bool p;
	void input();
	void update();
	void draw();
	void end();

public:

	bool start();
	void play();

};


#endif 
