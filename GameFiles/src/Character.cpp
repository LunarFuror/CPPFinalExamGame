/*
 * Way over Done
 * Character.cpp
 * Author: Grayson Lorenz
 * 2/21/2014
 */

#include"Character.h"

// Constructors #################################################################################
Character::Character(){
	setName("Default Dale");
	setMaxHealth(50);
	setCurrentHealth(getMaxHealth());
	setAttack(20);
	setDefense(.05);
	setCritChance(100);
	setSpeed(10);
	setClass(5);
	srand(time(0));
}

Character::Character(std::string name, int health, int maxHealth, int atk, double def){
	setName(name);
	setMaxHealth(maxHealth);
	setCurrentHealth(health);
	setAttack(atk);
	setDefense(def);
	setCritChance(100);
	setSpeed(10);
	setClass(5);
	srand(time(0));
}


Character::Character(std::string name, int health, int maxHealth, int atk, double def, int speed, int crit,int type){
	setName(name);
	setMaxHealth(health);
	setCurrentHealth(health);
	setAttack(atk);
	setDefense(def);
	setCritChance(100);
	setSpeed(speed);
	setClass(5);
	setClass(type);
	srand(time(0));
}

// Getters Setters ################################################################################
std::string Character::getName(){
	return characterName;
}

void Character::setName(std::string name){
	if(name.size() <= 16){
		characterName = name;
	}
	if(name.size() > 16){
		characterName = name.substr(0,16);
		sleep(1);
	}
}

void Character::setMaxHealth(int maxHealth) {
	if(maxHealth <= 1) {
		characterMaxHealth = 1;
	}

	else if(maxHealth > 1){
		characterMaxHealth = maxHealth;
	}
}

int Character::getMaxHealth(){
	return characterMaxHealth;
}

int Character::getCurrentHealth() {
	return characterHealth;
}

void Character::setCurrentHealth(int health) {
	if(health <= 0){
		characterHealth = 0;
	}

	else if(health < getMaxHealth() && health > 0) {
		characterHealth = health;
	}

	else if(health >= getMaxHealth())	{
		characterHealth = getMaxHealth();
	}

	setState();
}

int Character::getAttack() {
	return characterAtk;
}

void Character::setAttack(int atk){
	if(atk <= 1) {
		characterAtk = 1;
	}
	else if(atk > 1){
		characterAtk = atk;
	}
}

double Character::getDefense() {
	return characterDef;
}

void Character::setDefense(double def) {
	if(def <= 0) {
		characterDef = 0;
	}
	else if(def > 0) {
		characterDef = def;
	}
}

int Character::getState(){
	return characterState;
}

std::string Character::getStateText(){
	std::string cState;
	switch(getState()){
		case BLOODY: cState = "bloody"; break;
		case NORMAL: cState = "normal"; break;
		case DEAD: cState = "dead"; break;
		default: cState = "unknown"; break;
	}
	return cState;
}

void Character::setState(){
	if(getCurrentHealth() == 0){ // dead
		characterState = DEAD;
	}
	else if(getCurrentHealth() > 0 && getCurrentHealth() <= getMaxHealth() / 2){ //bloody
		characterState = BLOODY;
	}
	else if(getCurrentHealth() > getMaxHealth() / 2){ // normal
		characterState = NORMAL;
	}
}

void Character::setCritChance(int crit){ //uses this number for generating random later. Crit = 1 means 100% crit rate. crit lower = better chance to crit, crit higher = worse chance to crit
	if(crit <= 1){
		characterCritChance = 1;
	}
	else{
		characterCritChance = crit;
	}
}

int Character::getCritChance(){
	return characterCritChance;
}

void Character::setSpeed(int speed){
	if(speed <= 0){
		characterSpeed = 0;
	}
	else{
		characterSpeed = speed;
	}
}

int Character::getSpeed(){
	return characterSpeed;
}

void Character::setClass(int choice){
	switch(choice){
		case 1: characterClass = WARRIOR; break;
		case 2: characterClass = GUARD; break;
		case 3: characterClass = THEIF; break;
		case 4: characterClass = TACO; break;
		case 5: characterClass = BLOB; break;
		case 6: characterClass = SKELETON; break;
		case 7: characterClass = TACOSUPREME; break;
		default: break;
	}
}

int Character::getClass(){
	return characterClass;
}

void Character::setNormalPic(std::string pic){
	normalPicture = pic;
}

std::string Character::getNormalPic(){
	return normalPicture;
}

// Do dat stuff ###################################################################
int Character::attack(){
	int damage;

	damage = (getAttack() * ((rand() % 26) + 75)) / 100;

	if(rand() % getCritChance() == 0){ // chance to crit trope
		if(rand() % 100 == 77){ // 1% chance for your crit to crit, always doing 3x max attack. #include<yoloSwag>
			damage = getAttack() * 3;
		}
		else{
			damage = (damage * 150) / 100;
		}
	}

	return damage;
}

int Character::takeDamage(int damage){
	int hurtFor;

	if(damage- (damage * getDefense()) < getMaxHealth() * .05){ // 50% chance to block when damage dealt is less than 5% of max health
		if(rand() % 2 == 1){
			damage = 0;
		}
	}
	else if(damage - (damage * getDefense()) < getMaxHealth() * .1){ // 1% chance to block when damage dealt is less than 10% of max health
		if(rand() % 100 == 77){
			damage = 0;
		}
	}

	hurtFor = damage - (damage * getDefense());
	setCurrentHealth(getCurrentHealth() - hurtFor);

	return hurtFor;
}

int Character::fullHeal(){
	int healed;

	healed = getMaxHealth() - getCurrentHealth();

	setCurrentHealth(healed + getCurrentHealth());

	return healed;
}

int Character::heal(int healed){
	if(getState() == DEAD){
		healed = 0;
	}
	else{
		setCurrentHealth(healed + getCurrentHealth());
	}
	return healed;
}

void Character::revive(){
	if(getState() == DEAD){
		setCurrentHealth(getMaxHealth() / 10);
	}
}
