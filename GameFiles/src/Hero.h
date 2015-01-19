/*
 * Hero.h
 *
 *  Created on: May 7, 2014
 *      Author: lunarfuror
 */

#ifndef HERO_H_
#define HERO_H_

#include "Character.h"

class Hero : public Character
{
	public:
		Hero();
		Hero(std::string, int, int, double, int, int, int);
		Hero(std::string, int, int, int, double, int, int, int, int, int);

		bool gainExperience(int);
		void levelUp();
		bool isLevelAble();

		int getExperience();
		void setExperience(int);
		int getLevel();
		void setLevel(int);

	private:
		int level;
		int experience;
};


#endif /* HERO_H_ */
