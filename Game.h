#ifndef GAME_H
#define GAME_H

#include <SDL.h>
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
	void input();
	void update();
	void draw();
	void end();

public:

	bool start();
	void play();

};


#endif 