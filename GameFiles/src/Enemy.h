/*
 * Enemy.h
 *
 *  Created on: May 7, 2014
 *      Author: lunarfuror
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "Character.h"

class Enemy : public Character{
	public:
		Enemy();
		Enemy(std::string, int, int, double, int, int);
		Enemy(std::string, int, int, double, int, int, std::string);

		std::string getBattleCry();
		void setBattleCry(std::string);
	private:
		std::string battleCry;
};

#endif /* ENEMY_H_ */
