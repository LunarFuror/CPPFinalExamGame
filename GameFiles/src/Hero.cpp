/*
 * Hero.cpp
 *
 *  Created on: May 7, 2014
 *      Author: lunarfuror
 */

#include "Hero.h"
Hero::Hero(){
	Character("Dale", 100, 100, 100, .05, 10, 100, 1);
	setLevel(1);
	setExperience(0);
}
Hero::Hero(std::string name, int atk, int health, double def, int speed, int type, int crit){
	Character(name, atk, health, health, def, speed, crit, type);
	setLevel(1);
	setExperience(0);
}
Hero::Hero(std::string name, int atk, int health, int maxHealth, double def, int speed, int type, int crit, int level, int exper){
	Character(name, atk, health, maxHealth, def, speed, crit, type);
	setLevel(level);
	setExperience(exper);
}

bool Hero::gainExperience(int exper){
	setExperience(getExperience() + exper);
	if(isLevelAble()){
		levelUp();
		return true;
	}
	else{
		return false;
	}
}
void Hero::levelUp(){
	setLevel(getLevel() + 1);
	setMaxHealth(getMaxHealth() + (getMaxHealth()/10));
	setAttack(getAttack() + (getAttack()/10));
	if(getDefense() + .01 < .6){
		setDefense(getDefense() + .01);
	}
	setSpeed(getSpeed() + 1);
	setExperience(getExperience() - 120);
	if(isLevelAble()){
		levelUp();
	}
}
bool Hero::isLevelAble(){
	if(getExperience() >= 120){
		return true;
	}
	else{
		return false;
	}
}

int Hero::getExperience(){
	return experience;
}
void Hero::setExperience(int exper){
	if(exper < 0){
		exper = 0;
	}
	experience = exper;
}
int Hero::getLevel(){
	return level;
}
void Hero::setLevel(int lvl){
	if(lvl < 1){
		lvl = 1;
	}
	level = lvl;
}

