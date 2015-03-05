#include "PCPlat.h"
#include"Global.h"
#include "Ball.h"

#define SPEED 0.5

void PCPlat::update()
{
	
	//modo facil

	/*if (bola->vx > 0)
	{
		if(bola->y > y )
		{
			v+=SPEED;
		}

		else if(bola->y < y )
		{
			v-=SPEED;
		}
	}*/
	

	if (bola->vx > 0)
	{
		if(bola->positionBall() -15 > y )
		{
			v+=SPEED;
		}

		else if(bola->positionBall() + 15 < y )
		{
			v-=SPEED;
		}
	}
	
	else
	{
		if(SCREEN_HEIGHT / 2 -30 > y+height/2 )
		{
			v+=SPEED;
		}

		else if(SCREEN_HEIGHT / 2 + 30 < y+height/2 )
		{
			v-=SPEED;
		}

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