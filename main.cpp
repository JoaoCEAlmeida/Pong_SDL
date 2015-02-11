#include <SDL.h>
#include "Game.h"

#undef main

int main(){

	Game game;
	
	if(!game.start())
		return 1;

	game.play();

	return 0;
}