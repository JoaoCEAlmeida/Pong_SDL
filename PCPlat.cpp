#include "PCPlat.h"
#include"Global.h"


void PCPlat::update()
{
	if(y+height+v > SCREEN_HEIGHT)
	{

		y=SCREEN_HEIGHT-height;
		v=0;

	}

	if(y+v < 0)
	{

		y=0;
		v=0;

	}

	y+=v;
}