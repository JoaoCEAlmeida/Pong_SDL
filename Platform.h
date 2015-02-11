#ifndef PLATFORM_H
#define PLATFORM_H

#if defined __linux__
#include <SDL2/SDL.h>
#elif defined _WIN32
#include <SDL.h>
#endif

class Platform
{
protected:

	int x,y,height,width;
	float v;

public:

	virtual void update()=0;
	void draw(SDL_Renderer* renderer);
};


#endif
