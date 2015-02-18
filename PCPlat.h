#ifndef PCPLAT_H
#define PCPLAT_H

#include"Platform.h"

class Ball;

class PCPlat: public Platform
{
	Ball * bola;

public:

	PCPlat(int x,int y,int height, int width, Ball* bola)
	{
		this->x=x;
		this->y=y;
		this->height=height;
		this->width=width;
		this->v=0;
		this->bola = bola;
	}
	
	void update();

};

#endif