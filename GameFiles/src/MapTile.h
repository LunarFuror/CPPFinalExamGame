/*
 * MapTile.h
 *
 *  Created on: Apr 5, 2014
 *      Author: lunarfuror
 */

#ifndef MAPTILE_H_
#define MAPTILE_H_

#include<string>
#include<ostream>
#include<vector>
#include<exception>
#include<sstream>
#include "Enemy.h"
#include "Hero.h"

class MapTile{
		friend std::ostream &operator<<( std::ostream &, const MapTile &);
	public:
		MapTile();
		MapTile(std::string);
		MapTile(std::string, std::vector<Enemy> *);

		void setDescription(std::string);
		std::string getDescription() const;
		void setEnemyArray(std::vector<Enemy> *);
		int getArraySize() const;
		Enemy& getNextEnemy();
		const std::vector<Enemy> * getEnemyArray() const;
		void setTile(char);
		char getDisplayTile()const;
		char getTile()const;

		bool hasEnemiesLeft() const;
		int numEnemiesLeft() const;
		bool getHasKey() const;
		void setHasKey(bool);
		bool getHasPotion() const;
		void setHasPotion(bool);
		~MapTile();

	private:
		bool hasKey;
		bool hasPotion;
		int arraySize;
		std::string description;
		std::vector<Enemy> enemies;
		char tileChar;
};


#endif /* MAPTILE_H_ */
