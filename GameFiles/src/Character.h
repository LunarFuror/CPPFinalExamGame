/*
 * Way over Done
 * Character.h
 * Author: Grayson Lorenz
 * 2/21/2014
 */
#ifndef CHARACTER_H_
#define CHARACTER_H_

#if (defined(_WIN32) || defined(_WIN64) || defined(WINDOWS_OS))
	#include <time.h>
	#include <windows.h>
	#ifndef WINDOWS_OS
		#define WINDOWS_OS
	#endif
#elif __linux
// linux
#endif

#include<iostream>
#include<string>
#include<cstdlib>

class Character{
	public:
		enum State{
			NORMAL,
			BLOODY,
			DEAD
		};
		enum ClassType{
			WARRIOR,
			GUARD,
			THEIF,
			TACO,
			SKELETON,
			BLOB,
			TACOSUPREME
		};
		//Constructors
		Character();
		Character(std::string, int, int, int, double);
		Character(std::string, int, int, int, double, int, int, int);

		//Getters and Setters
		std::string getName();
		void setName(std::string);
		void setMaxHealth(int);
		int getMaxHealth();
		int getCurrentHealth();
		void setCurrentHealth(int);
		int getAttack();
		void setAttack(int);
		double getDefense();
		void setDefense(double);
		int getState();
		std::string getStateText();
		void setState();
		void setCritChance(int);
		int getCritChance();
		void setSpeed(int);
		int getSpeed();
		void setClass(int);
		int getClass();
		void setNormalPic(std::string);
		std::string getNormalPic();
		void setBloodPic(std::string);
		std::string getBloodPic();
		void setDeadPic(std::string);
		std::string getDeadPic();

		//Do the do
		int takeDamage(int);
		int attack();
		int fullHeal();
		int heal(int);
		void revive();

	private:
		std::string characterName;
		int characterMaxHealth;
		int characterHealth;
		int characterAtk;
		int characterSpeed;
		double characterDef;
	  State characterState;
	  int characterCritChance;
	  ClassType characterClass;
	  std::string normalPicture;
	  std::string bloodyPicture;
	  std::string deadPicture;
};

#endif
