#ifndef JOGADORPLAT_H
#define JOGADORPLAT_H

#include"Platform.h"

class JogadorPlat: public Platform
{

public:

	JogadorPlat(int x,int y,int height, int width)
	{
		this->x=x;
		this->y=y;
		this->height=height;
		this->width=width;
		this->v=0;
	}
	
	void update();

};

#endif