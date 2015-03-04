#ifndef LINE_H
#define LINE_H

#if defined __linux__
#include <SDL2/SDL.h>
#elif defined _WIN32
#include <SDL.h>
#endif

class Line
{
public:

	int x,y,altura,largura;

	void drawLine(SDL_Renderer* renderer);
	void update();

	Line(int x,int y, int largura,int altura)
	{
		this->x=x;
		this->y=y;
		this->altura=altura;
		this->largura = largura;
	}

};

#endif