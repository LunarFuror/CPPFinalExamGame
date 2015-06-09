/*
 * Way over Done
 * Display.h
 * Author: Grayson Lorenz
 * 2/21/2014
 */
#ifndef DISPLAY_H_
#define DISPLAY_H_
#if (defined(_WIN32) || defined(_WIN64) || defined(WINDOWS_OS))
	#include <windows.h>
	#ifndef WINDOWS_OS
		#define WINDOWS_OS
	#endif
#elif __linux
// linux
#endif
#include <iostream>
#include <string>
#include <array>
#include "Map.h"
class Display{
	public:
		Display();
		void clearScreen();
		void setMenu(int);
		int getMenu();
		std::string drawHealthBar(Character &);
		std::string drawName(Character &);
		std::string drawLevel(Hero &);
		std::string drawStatus(Character &);
		void drawStatusBoxes(Hero &, Character &);
		void drawStatusEmpty();
		void drawStatusTitle();
		void drawStatusMap(Hero &);
		void drawPictureBoxes(Character &, Character &);
		void drawPictureMap(std::string, std::string);
		void drawPictureClass();
		void drawPictureTitle();
		void drawPictureCredits();
		void drawPictureHelp();
		void drawPictureLegend();
		void drawMenuBoxes(std::string, std::string, std::string, std::string, int, int, int);
		void drawBattle(Hero &, Character &, std::string, std::string, std::string, std::string, int, int, int);
		void drawEmpty(std::string, std::string, std::string, std::string, int, int, int);
		void drawTitle(std::string, std::string, std::string, std::string, int, int, int);
		void drawHelp(std::string, std::string, std::string, std::string, int, int, int);
		void drawCredits(std::string, std::string, std::string, std::string, int, int, int);
		void drawLegend(std::string, std::string, std::string, std::string, int, int, int);
		void drawMap(Hero &, std::string, std::string, std::string, std::string, std::string, std::string, int, int, int);

	private:
		int menu;
};

#endif
