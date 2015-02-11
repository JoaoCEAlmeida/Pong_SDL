#ifndef PCPLAT_H
#define PCPLAT_H

#include"Platform.h"

class PCPlat: public Platform
{

public:

	PCPlat(int x,int y,int height, int width)
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