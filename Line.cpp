#include"Line.h"

void Line::drawLine(SDL_Renderer* renderer)
{
	SDL_Rect rect={x,y,largura,altura};
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderFillRect(renderer,&rect);
}