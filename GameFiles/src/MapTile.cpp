/*
 * MapTile.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: lunarfuror
 */

#include "MapTile.h"


MapTile::MapTile(){
	std::vector<Enemy> blankPtr;
	setEnemyArray(&blankPtr);
	setHasKey(false);
	setHasPotion(false);
	setDescription("You see a default room        description. Something about  cats is written on the wall.");
	tileChar= ' ';
}

MapTile::MapTile(std::string inDesc){
	std::vector<Enemy> blankPtr;
	setEnemyArray(&blankPtr);
	setHasKey(false);
	setHasPotion(false);
	setDescription(inDesc);
	tileChar = ' ';
}

MapTile::MapTile(std::string inDesc, std::vector<Enemy> * inEnemy){
	setEnemyArray(inEnemy);
	setHasKey(false);
	setHasPotion(false);
	setDescription(inDesc);
	tileChar = ' ';
}

//For now, change to generic descriptions.
void MapTile::setDescription(std::string inDesc){
	//Fill in room description
	if(inDesc.length() > 180){
		inDesc = inDesc.substr(0,179);
	}
	while(inDesc.length() < 180){
		inDesc += " ";
	}

	description = inDesc;
}

//fix this
std::string MapTile::getDescription() const{
	std::stringstream stream;
	std::string inDesc = "";
	//Stuff to pick up? Let them know!
	if(getHasKey()){
		inDesc += "There's a key on the floor.";
	}
	else if(getHasPotion()){
		inDesc += "There's a bottle on the floor.";
	}
	else{
		inDesc += "You see nothing of real use.";
	}

	while(inDesc.length() < 30){
			inDesc += " ";
	}

	//Enemies left? Lettem know
	if(hasEnemiesLeft()){
		stream << "Enemies not dead yet: " << numEnemiesLeft();
		inDesc += stream.str();
	}
	else{
		inDesc += "ROOM PURIFIED!";
	}

	//Pad description. probably should put this in the display class... meh.
	while(inDesc.length() < 60){
		inDesc += " ";
	}
	return description + inDesc;
}
/*
 * returns true if there are enemies left...
 */
bool MapTile::hasEnemiesLeft() const{
	if(numEnemiesLeft() == 0){
		return false;
	}
	else{
		return true;
	}
}
/*
 * returns number of enemies left
 */
int MapTile::numEnemiesLeft() const{
	int enemyCount = 0;

	for(Enemy testEnemy: enemies){
		if(testEnemy.getState() != Enemy::DEAD){
			enemyCount ++;
		}
	}

	return enemyCount;
}
/*
 * returns next not dead enemy
 */
Enemy& MapTile::getNextEnemy(){
	if(hasEnemiesLeft()){
		return enemies[enemies.size() - numEnemiesLeft()];
	}
	throw std::exception();
}

const std::vector<Enemy> * MapTile::getEnemyArray() const{
	const std::vector<Enemy> * enemiesPtr = &enemies;
	return enemiesPtr;
}
/*
 * sets the array of enemies for this room
 */
void MapTile::setEnemyArray(std::vector<Enemy> * inEnemyArray){
	enemies = * inEnemyArray;
}
/*
 * still not sure why this exists...
 */
int MapTile::getArraySize() const{
	const int size = enemies.size();
	return size;
}
/*
 * never used but that's cool
 */
std::ostream &operator<<( std::ostream & output, const MapTile & map){
	if(map.numEnemiesLeft() != 0){
		output << "You see:" << map.getDescription() << "\n There are " << map.numEnemiesLeft() << " enemies left.";
	}
	else{
		output << "You see:" << map.getDescription();
	}

	return output;
}

//Certain tile chars (. and ? specifically) are used to tell if the room is enterable
void MapTile::setTile(char disp){
	tileChar = disp;
}

//hides tiles to keep screen clutter free

char MapTile::getDisplayTile() const{
	char displayTile = tileChar;
	switch(displayTile){
		case '?': displayTile = ' '; break;
		case '.':
			if(getHasKey()){
				displayTile = 'k';
			}
			else if(getHasPotion()){
				displayTile = 'p';
			}
			else{
				displayTile = ' ';
			}
			break;
		case 'L': displayTile = ' '; break;
		case 'e': displayTile = ' '; break;
		case 'V': displayTile = ' '; break;
	}


	return displayTile;
}

char MapTile::getTile() const{
	return tileChar;
}

bool MapTile::getHasKey() const{
	return hasKey;
}

void MapTile::setHasKey(bool key){
	hasKey = key;
}

bool MapTile::getHasPotion() const{
	return hasPotion;
}

void MapTile::setHasPotion(bool potion){
	hasPotion = potion;
}

MapTile::~MapTile(){

}
