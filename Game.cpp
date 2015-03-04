#include "Game.h"
#include "JogadorPlat.h"
#include "PCPlat.h"
#include"Ball.h"
#include"Global.h"
#include "Line.h"
#include <Windows.h>

bool Game::start()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return false;
	else {

		gameWindow = SDL_CreateWindow("Pong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);

	}

	done = false;
	p=false;
	ball = new Ball(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,8);

	Line* line = new Line(SCREEN_WIDTH/2 - 1,0,2,10);
	Line* line1 = new Line(SCREEN_WIDTH/2 - 1,16,2,10);
	Line* line2 = new Line(SCREEN_WIDTH/2 - 1,32,2,10);
	Line* line3 = new Line(SCREEN_WIDTH/2 - 1,48,2,10);
	Line* line4 = new Line(SCREEN_WIDTH/2 - 1,64,2,10);
	Line* line5 = new Line(SCREEN_WIDTH/2 - 1,80,2,10);
	Line* line6 = new Line(SCREEN_WIDTH/2 - 1,96,2,10);
	Line* line7 = new Line(SCREEN_WIDTH/2 - 1,112,2,10);
	Line* line8 = new Line(SCREEN_WIDTH/2 - 1,128,2,10);
	Line* line9 = new Line(SCREEN_WIDTH/2 - 1,144,2,10);
	Line* line10 = new Line(SCREEN_WIDTH/2 - 1,160,2,10);
	Line* line11 = new Line(SCREEN_WIDTH/2 - 1,176,2,10);
	Line* line12 = new Line(SCREEN_WIDTH/2 - 1,192,2,10);
	Line* line13 = new Line(SCREEN_WIDTH/2 - 1,208,2,10);
	Line* line14 = new Line(SCREEN_WIDTH/2 - 1,224,2,10);
	Line* line15 = new Line(SCREEN_WIDTH/2 - 1,240,2,10);
	Line* line16 = new Line(SCREEN_WIDTH/2 - 1,256,2,10);
	Line* line17 = new Line(SCREEN_WIDTH/2 - 1,272,2,10);
	Line* line18 = new Line(SCREEN_WIDTH/2 - 1,288,2,10);
	Line* line19 = new Line(SCREEN_WIDTH/2 - 1,304,2,10);
	Line* line20 = new Line(SCREEN_WIDTH/2 - 1,320,2,10);
	Line* line21 = new Line(SCREEN_WIDTH/2 - 1,336,2,10);
	Line* line22 = new Line(SCREEN_WIDTH/2 - 1,352,2,10);
	Line* line23 = new Line(SCREEN_WIDTH/2 - 1,368,2,10);
	Line* line24 = new Line(SCREEN_WIDTH/2 - 1,384,2,10);
	Line* line25 = new Line(SCREEN_WIDTH/2 - 1,400,2,10);
	Line* line26 = new Line(SCREEN_WIDTH/2 - 1,416,2,10);
	Line* line27 = new Line(SCREEN_WIDTH/2 - 1,432,2,10);
	Line* line28 = new Line(SCREEN_WIDTH/2 - 1,448,2,10);
	Line* line29 = new Line(SCREEN_WIDTH/2 - 1,464,2,10);

	Platform* player = new JogadorPlat(5,SCREEN_HEIGHT/2,50,10);
	Platform* PC = new PCPlat(SCREEN_WIDTH-5-10,SCREEN_HEIGHT/2,50,10,ball);

	platforms.push_back(player);
	platforms.push_back(PC);

	lines.push_back(line);
	lines.push_back(line1);
	lines.push_back(line2);
	lines.push_back(line3);
	lines.push_back(line4);
	lines.push_back(line5);
	lines.push_back(line6);
	lines.push_back(line7);
	lines.push_back(line8);
	lines.push_back(line9);
	lines.push_back(line10);
	lines.push_back(line11);
	lines.push_back(line12);
	lines.push_back(line13);
	lines.push_back(line14);
	lines.push_back(line15);
	lines.push_back(line16);
	lines.push_back(line17);
	lines.push_back(line18);
	lines.push_back(line19);
	lines.push_back(line20);
	lines.push_back(line21);
	lines.push_back(line22);
	lines.push_back(line23);
	lines.push_back(line24);
	lines.push_back(line25);
	lines.push_back(line26);
	lines.push_back(line27);
	lines.push_back(line28);
	lines.push_back(line29);

	return true;

}

void Game::play()
{

	while(!done)
	{
		input();

		if(!p)
		{
			update();
		}
			draw();
			SDL_Delay(1000/60);		
	}

	end();

}

void Game::input()
{
	while(SDL_PollEvent(&gameEvent))
	{
		switch(gameEvent.type)
		{
			case SDL_QUIT:
				done = true;
				break;

			case SDL_KEYDOWN:
				if(gameEvent.key.keysym.sym==SDLK_ESCAPE)
					done=true;
				if(gameEvent.key.keysym.sym == SDLK_UP)
					moveUp = true;
				if(gameEvent.key.keysym.sym == SDLK_DOWN)
					moveDown = true;
				if(gameEvent.key.keysym.sym == SDLK_p)
				{
					if(p) p=false;
					else
						p=true;
				}
	
				break;

			case SDL_KEYUP:
				if(gameEvent.key.keysym.sym == SDLK_UP)
					moveUp = false;
				if(gameEvent.key.keysym.sym == SDLK_DOWN)
					moveDown = false;
		}
	}
}

void Game::update()
{
	for(unsigned int i=0; i < platforms.size(); i++)
	{
		platforms[i]->update();
	}

		ball->update(platforms);
}

void Game::draw()
{
	SDL_SetRenderDrawColor(gameRenderer,0,0,0,255);
	SDL_RenderClear(gameRenderer);

	for(unsigned int k=0; k < lines.size(); k++)
	{
		lines[k]->drawLine(gameRenderer);
	}
	

	for(unsigned int i=0; i < platforms.size(); i++)
	{
		platforms[i]->draw(gameRenderer);
	}

	ball->draw(gameRenderer);

	SDL_RenderPresent(gameRenderer);
}


void Game::end()
{
	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(gameRenderer);

	SDL_Quit();
}