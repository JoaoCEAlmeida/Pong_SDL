#include"Ball.h"
#include"Global.h"
#include"Platform.h"

void Ball::update(std::vector<Platform*> platforms)
{
	if(x+size+vx > SCREEN_WIDTH)
	{

		x=SCREEN_WIDTH-size;
		vx*=-1;

	}

	if(x+vx < 0)
	{

		x=0;
		vx*=-1;

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
