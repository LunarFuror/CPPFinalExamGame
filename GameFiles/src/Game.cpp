/*
 * Completely Overdone 1.2
 * Game.cpp
 * Author: Grayson Lorenz
 */

#include<iostream>
#include<string>
#include<cstdlib>
#include"Controll.h"

int main(){
	Controll game(10);
	Hero player;
	Enemy enemy;

 while(game.introMenu()){
		game.setYourName(player);
		game.chooseClass(player);

		while(game.play(player)){
			game.mapMenu(player);
		}
		game.resetGame();
	}
	game.newMessageEmpty("Thanks for playing my award winning game!", 7);
	return 0;
}
