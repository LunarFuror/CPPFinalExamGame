/*
 * Way over Done
 * Controll.h
 * Author: Grayson Lorenz
 * 2/21/2014
 */

#ifndef CONTROLL_H_
#define CONTROLL_H_

#include<iostream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<exception>
#include"Display.h"

class Controll{
	public:
		//constructors
		Controll();
		Controll(int);

		//Getters and setters
		void setPotionsRemaining(int);
		int getPotionsRemaining();
		void setKeysRemaining(int);
		int getKeysRemaining();
		void setLine1(std::string);
		void setLine2(std::string);
		void setLine3(std::string);
		void setLine4(std::string);
		std::string getLine1();
		std::string getLine2();
		std::string getLine3();
		std::string getLine4();

		//set up stuff
		bool introMenu();
		void helpMenu();
		void legendMenu();
		void creditsMenu();
		void setYourName(Hero&);
		void chooseClass(Hero&);
		void resetGame();
		int chooseCharacter();


		//combat stuff
		int combatMenu(Hero &, Enemy &);
		void Combat(Hero &, Enemy &);
		void turnPlayer(Hero &, Enemy &, int);
		void turnEnemy(Hero &, Enemy &);

		//map stuff
		bool doCombat();
		void mapMenu(Hero &);
		void moveMenu(Hero &);
		void invMenu(Hero &);
		void unlockMenu(Hero &);

		//send to display for ease of use
		void newMessage(Hero &, Enemy &, std::string, int);
		void newMessageEmpty(std::string, int);
		void newMessageTitle(std::string, int);
		void newMessageMap(Hero &, std::string, int);
		void newMessageHelp(std::string, int);
		void newMessageCredits(std::string, int);
		void newMessageLegend(std::string, int);
		void clearLines();
		bool play(Hero &);

	private:
		int ammountPotions;
		int ammountKeys;
		Display display;
		std::string line1;
		std::string line2;
		std::string line3;
		std::string line4;
		Map map;
};

#endif
