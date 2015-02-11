#ifndef PLATFORM_H
#define PLATFORM_H

#include<SDL.h>

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