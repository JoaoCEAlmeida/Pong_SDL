#include "Game.h"
#include "JogadorPlat.h"
#include "PCPlat.h"
#include"Ball.h"
#include"Global.h"

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

	Platform* player = new JogadorPlat(5,SCREEN_HEIGHT/2,50,10);
	Platform* PC = new PCPlat(SCREEN_WIDTH-5-10,SCREEN_HEIGHT/2,50,10,ball);

	platforms.push_back(player);
	platforms.push_back(PC);

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