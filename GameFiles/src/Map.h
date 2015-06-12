/*
 * Map.h
 *
 *  Created on: Apr 9, 2014
 *      Author: lunarfuror
 */

#ifndef MAP_H_
#define MAP_H_
#include "MapTile.h"
#include<array>
#include<fstream>
class Map{
	public:
		Map();
		int getCurrentFloor();
		bool canMove();
		bool canNorth();
		bool canSouth();
		bool canEast();
		bool canWest();
		void resetFloors();
		std::string getMapString();
		std::string getCurrentDescription();
		void sendExits();
		std::string randomDescription();

		void importMaps();
		void importEnemies();
		void importGroups();
		void importImages();
		void setUpRooms();
		void enterRoom();
		void moveNorth();
		void moveSouth();
		void moveEast();
		void moveWest();
		void nextFloor();
		int getFloorsCompleted();
		Enemy& getEnemy();
		bool unlock(int);
		bool takeKey();
		bool takePotion();

	private:
		std::array<std::array < MapTile, 30>, 8> fullMap;
		std::array<int,2> curPos;
		std::string displayString;
		std::vector<std::string> maps;
		std::vector<std::string> enemyMaps;
		std::vector<Enemy> enemies;
		std::vector<std::vector<Enemy> > enemyGroups;
		std::ifstream inMaps;
		std::ifstream inEnemies;
		std::ifstream inGroups;
		std::ifstream inImages;
		std::string buffer;
		int floorsCompleted;
		unsigned int currentFloor;
};

#endif


