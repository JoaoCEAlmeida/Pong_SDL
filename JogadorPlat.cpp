#include "JogadorPlat.h"
#include"Global.h"
#include<Math.h>

#define SPEED 0.5

void JogadorPlat::update()
{
	if(moveUp)
	{
		v-= SPEED;
	}

	else if (moveDown)
	{
		v+=SPEED;
	}

	else if(fabs(v) < 0.5)
	{
		v=0;
	}


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

	v*=0.95;
	y+=v;
}