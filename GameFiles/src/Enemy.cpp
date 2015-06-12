/*
 * Enemy.cpp
 *
 *  Created on: May 7, 2014
 *      Author: lunarfuror
 */

#include "Enemy.h"

Enemy::Enemy(){
	Character("Tucker", 10, 50, 50, .05, 10, 100, 4);
	setBattleCry("Oh imma getcha!");
}

Enemy::Enemy(std::string name, int atk, int health, double def, int speed, int type){
	Character(name, atk, health, health, def, speed, 100, type);
	setBattleCry("Oh imma getcha!");
}

Enemy::Enemy(std::string name, int atk, int health, double def, int speed, int type, std::string cry){
	Character(name, atk, health, health, def, speed, 100, type);
	setBattleCry(cry);
}

std::string Enemy::getBattleCry(){
	return battleCry;
}
void Enemy::setBattleCry(std::string cry){
	battleCry = cry;
}

