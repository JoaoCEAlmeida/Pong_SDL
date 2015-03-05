#include"Ball.h"
#include"Global.h"
#include"Platform.h"
#include <windows.h>

void Ball::update(std::vector<Platform*> platforms)
{
	for(unsigned int i=0; i < platforms.size(); i++)
	{
		if(platforms[i]->y < y+size &&  platforms[i]->y+platforms[i]->height > y)
		{
			if(x < platforms[i]->x + platforms[i]->width && platforms[i]->x < SCREEN_WIDTH/2 && vx < 0 )
			{
				vx*=-1;
				vy += platforms[i]->v;

			}

			else if(x + size > platforms[i]->x  &&  platforms[i]->x > SCREEN_WIDTH/2 && vx > 0)
			{
				vx*=-1;
				vy += platforms[i]->v;
			}
		}

	}

	if(x+size+vx > SCREEN_WIDTH)
	{
		y=SCREEN_HEIGHT / 2;
		x=SCREEN_WIDTH/2;
		vx *= -1;
		vy = 0;
		scores++;
		Sleep(1000);
		
	}

	if(x+vx < 0)
	{
		y=SCREEN_HEIGHT / 2;
		x=SCREEN_WIDTH/2;
		vx *= -1;
		vy = 0;
		scoresPC++;
		Sleep(1000);

	}

	if(y+size+vy > SCREEN_HEIGHT)
	{

		y=SCREEN_HEIGHT-size;
		vy*=-1;

	}

	if(y+vy < 0)
	{

		y=0;
		vy*=-1;

	}

	x+=vx;
	y+=vy;
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect={x,y,size,size};
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderFillRect(renderer,&rect);

}


int Ball::positionBall()
{
	int y1=y,x1=x;
	double vx1=vx,vy1=vy;
	while(x1+size+vx1 < SCREEN_WIDTH - 10)
	{
	if(y1+size+vy1 > SCREEN_HEIGHT)
	{

		y1=SCREEN_HEIGHT-size;
		vy1*=-1;

	}

	if(y1+vy1 < 0)
	{

		y1=0;
		vy1*=-1;

	}
	
	x1+=vx1;
	y1+=vy1;
	}

	return y1;
}
