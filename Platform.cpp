#include "Platform.h"
#include"Global.h"
#include<SDL.h>

void Platform::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect={x,y,width,height};
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderFillRect(renderer,&rect);
}