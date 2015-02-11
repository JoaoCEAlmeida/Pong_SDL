#include "Platform.h"
#include"Global.h"

#if defined __linux__
#include <SDL2/SDL.h>
#elif defined _WIN32
#include <SDL.h>
#endif

void Platform::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect={x,y,width,height};
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderFillRect(renderer,&rect);
}
