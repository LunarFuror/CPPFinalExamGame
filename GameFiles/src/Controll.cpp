/*
 * Way over Done
 * Controll.cpp
 * Author: Grayson Lorenz
 * 2/21/2014
 */

#include"Controll.h"

//Constructors ###############################################

Controll::Controll(){
	setPotionsRemaining(10);
	setKeysRemaining(0);
	setLine1("");
	setLine2("");
	setLine3("");
	setLine4("");
}

Controll::Controll(int potions){
	setPotionsRemaining(potions);
	setKeysRemaining(0);
	setLine1("");
	setLine2("");
	setLine3("");
	setLine4("");
}

//Getters and setters ########################################

void Controll::setPotionsRemaining(int potions){
	if(potions <= 0){
		ammountPotions = 0;
	}
	else{
		ammountPotions = potions;
	}
}

int Controll::getPotionsRemaining(){
	return ammountPotions;
}

void Controll::setKeysRemaining(int keys){
	if(keys <= 0){
		ammountKeys = 0;
	}
	else{
		ammountKeys = keys;
	}
}

int Controll::getKeysRemaining(){
	return ammountKeys;
}

void Controll::setLine1(std::string line){
	if(line.length() > 50){
		line = line.substr(0,50);
	}
	line1 = line;
}

void Controll::setLine2(std::string line){
	if(line.length() > 50){
		line = line.substr(0,50);
	}
	line2 = line;
}

void Controll::setLine3(std::string line){
	if(line.length() > 50){
		line = line.substr(0,50);
	}
	line3 = line;
}

void Controll::setLine4(std::string line){
	if(line.length() > 50){
		line = line.substr(0,50);
	}
	line4 = line;
}

std::string Controll::getLine1(){
	return line1;
}

std::string Controll::getLine2(){
	return line2;
}

std::string Controll::getLine3(){
	return line3;
}

std::string Controll::getLine4(){
	return line4;
}
//Do stuff ####################################################
/*
 * Yet to be implimented, 1. Begin, 2. Help, 3. Credits, 4. Quit
 */
bool Controll::introMenu(){
	int choice;
	std::string buffer;
	std::string output;

	while(choice != 4){
		output = "Enter your choice, then push enter. Choices -->";
		newMessageTitle(output, 9);
		std::cin >> choice;

		while(choice != 1 && choice != 2 && choice != 3 && choice != 4){
			std::cin.clear();
			getline(std::cin, buffer);
			output = "You must choose a number from the [menu] -->";
			newMessageTitle(output, 9);
			std::cin >> choice;
		}

		switch(choice){
			case 1: return true;
			case 2: helpMenu(); break;
			case 3: creditsMenu(); break;
			default: break;
		}
	}
	return false;
}

//display how to play 1. Return, 2. Legend
void Controll::helpMenu(){
	int choice;
	std::string buffer;
	std::string output;
	while(choice != 1){
		output = "Enter your choice, then push enter. Choices -->";
		newMessageHelp(output, 10);
		std::cin >> choice;

		while(choice != 1 && choice != 2){
			std::cin.clear();
			getline(std::cin, buffer);
			output = "You must choose a number from the [menu] -->";
			newMessageHelp(output, 10);
			std::cin >> choice;
		}
		switch(choice){
			case 2: legendMenu(); break;
			default: break;
		}
	}
}
// display map legend 1. Return (to help)
void Controll::legendMenu(){
	int choice;
	std::string buffer;
	std::string output;

	output = "Enter your choice, then push enter. Choices -->";
	newMessageLegend(output, 11);
	std::cin >> choice;

	while(choice != 1){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "You must choose a number from the [menu] -->";
		newMessageLegend(output, 11);
		std::cin >> choice;
	}
}
// display credits 1. Return (to intro)
void Controll::creditsMenu(){
	int choice;
	std::string buffer;
	std::string output;

	output = "Enter your choice, then push enter. Choices -->";
	newMessageCredits(output, 11);
	std::cin >> choice;

	while(choice != 1){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "You must choose a number from the [menu] -->";
		newMessageCredits(output, 11);
		std::cin >> choice;
	}
}
/*
 * Set's the player's name, so far this is the intro menu
 */
void Controll::setYourName(Hero &thePlayer){
	int choice = 2;
	std::string output = "";
	std::string name;
	std::string buffer;

	clearLines();
	getline(std::cin, buffer);

	while(choice == 2){

		newMessageTitle("What is your name?", 7);
		getline (std::cin, name); // because you may want 2 names or a name with a space in it.
		thePlayer.setName(name);
		output = "Your name is " + thePlayer.getName() + ". Is this ok?";
		newMessageTitle(output, 0);
		std::cin >> choice;

		//make sure people know how to use a basic menu
		while(choice != 1 && choice != 2){
			std::cin.clear();
			getline(std::cin, buffer);
			output = "Look... 1 or 2. Pick again!";
			newMessageTitle(output, 0);
			std::cin >> choice;
		}

		// if this isnt here cin stores eof and the loop auto puts that in for name and you are stuck with "" as a name.
		getline(std::cin, buffer);

	} // end loop

	output = thePlayer.getName() + ", hope you're proud of your self.";
	newMessageTitle(output, 7);
}
/*
 * Set's the player's class, quick and easy stuff
 */
void Controll::chooseClass(Hero &thePlayer){
	int choice;
	std::string buffer;
	std::string output;

	output = "Time to choose your cookie cutter class!";
	newMessageEmpty(output, 4);
	std::cin >> choice;
	while(choice != 1 && choice != 2 && choice != 3){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "Bet you tried that in the name menu too...";
		newMessageEmpty(output, 4);
		std::cin >> choice;
	}

	while(choice != 1 && choice != 2 && choice != 3){
		output = "Bet you tried that in the name menu too...";
		newMessageEmpty(output, 4);
		std::cin >> choice;
	}

		getline(std::cin, buffer); //buffer to clear cin completely flush, clear, and ignore weren't working...

		switch(choice){
			case 1: // warrior
				thePlayer.setMaxHealth(120);
				thePlayer.setCurrentHealth(thePlayer.getMaxHealth());
				thePlayer.setAttack(40);
				thePlayer.setDefense(.05);
				thePlayer.setCritChance(170);
				thePlayer.setSpeed(10);
				thePlayer.setClass(choice);
				break;

			case 2: // guard
				thePlayer.setMaxHealth(140);
				thePlayer.setCurrentHealth(thePlayer.getMaxHealth());
				thePlayer.setAttack(30);
				thePlayer.setDefense(.10);
				thePlayer.setCritChance(100);
				thePlayer.setSpeed(5);
				thePlayer.setClass(choice);
				thePlayer.setNormalPic(
						"        /'.   /\\   .'\\        "
						"       //  '--||--'  \\\\       "
						"      ||      ||      ||      "
						"      ||      ||      ||      "
						"       \\\\  .--||--.  //       "
						"        \\.'   ||   './        "
						"              ||              "
						"              ||              ");
				break;

			case 3: // assassin
				thePlayer.setMaxHealth(100);
				thePlayer.setCurrentHealth(thePlayer.getMaxHealth());
				thePlayer.setAttack(50);
				thePlayer.setDefense(.03);
				thePlayer.setCritChance(33);
				thePlayer.setSpeed(15);
				thePlayer.setClass(choice);
				break;
			default: break;
		}
}
/*
 * Combat flow, subject to change for enemy output, that may go to the enemy subclass later
 * handles who goes first, then goes to combat menu, then goes to turn player
 */
void Controll::Combat(Hero &thePlayer, Enemy &theEnemy){
	int choice;
	std::string output = "";
	std::stringstream stream;
	output = theEnemy.getBattleCry();
	newMessage(thePlayer, theEnemy, output, 1);
	if(thePlayer.getSpeed() >= theEnemy.getSpeed()){//you go first
		while(thePlayer.getState() != Character::DEAD && theEnemy.getState() != Character::DEAD ){
			choice = combatMenu(thePlayer, theEnemy);

			turnPlayer(thePlayer, theEnemy, choice);
			turnEnemy(thePlayer, theEnemy);
		}
	}
	else if(thePlayer.getSpeed() < theEnemy.getSpeed()){//enemy goes first
		while(thePlayer.getState() != Character::DEAD && theEnemy.getState() != Character::DEAD ){
			choice = combatMenu(thePlayer, theEnemy);

			turnEnemy(thePlayer, theEnemy);
			turnPlayer(thePlayer, theEnemy, choice);
		}
	}
	stream << "You gained " << (int)((theEnemy.getAttack() + theEnemy.getMaxHealth() + theEnemy.getSpeed() + (theEnemy.getCritChance()* theEnemy.getDefense())) / thePlayer.getLevel()) << " exp!";
	output = stream.str();
	newMessage(thePlayer, theEnemy, output, 7);
	if(thePlayer.gainExperience((int)((theEnemy.getAttack() + theEnemy.getMaxHealth() + theEnemy.getSpeed() + (theEnemy.getCritChance()* theEnemy.getDefense())) / thePlayer.getLevel()))){
		output = "You leveled up!";
		newMessage(thePlayer, theEnemy, output, 7);
	}
}
/*
 * Handles the choice you made in the combat menu
 */
void Controll::turnPlayer(Hero &thePlayer, Enemy& theEnemy, int choice){
	std::string output = "";
	std::stringstream stream;

	if(thePlayer.getState() != Character::DEAD){
		switch(choice){
				case 1: //Attack
					stream.clear();
					stream << theEnemy.getName() << " took " << theEnemy.takeDamage(thePlayer.attack()) << " damage!";
					output = stream.str();
					newMessage(thePlayer, theEnemy, output, 1);
					if(theEnemy.getState() == Character::DEAD){
						output = "(O,,,O) *bleh* " + theEnemy.getName() + " has died!";
						newMessage(thePlayer, theEnemy, output, 1);
					}
					break;

				case 2: //Heal
					stream.clear();
					stream << thePlayer.getName() << " healed " << thePlayer.heal(thePlayer.getMaxHealth() / 2) << " points of health.";
					output = stream.str();
					newMessage(thePlayer, theEnemy, output, 1);
					setPotionsRemaining(getPotionsRemaining() - 1);
					break;

				case 3: //Don't do stuff.
					switch(rand() % 4){
						case 0:
							output = thePlayer.getName() + " whistled while they worked.";
							newMessage(thePlayer, theEnemy, output, 1);
						break;

						case 1:
							output = "What a terrible night for a curse!";
							newMessage(thePlayer, theEnemy, output, 1);
						break;

						case 2:
							output = "Crickets chirp in the background.";
							newMessage(thePlayer, theEnemy, output, 1);
						break;

						case 3:
							output = thePlayer.getName() + " stood there. Is the oven on?";
							newMessage(thePlayer, theEnemy, output, 1);
						break;
					}
					break;
				default:
					newMessage(thePlayer, theEnemy, output, 1);
					break;
		}
	}
}
/*
 * basic enemy ai, may change when enemy subclass happens
 */
void Controll::turnEnemy(Hero &thePlayer, Enemy &theEnemy){
	std::string output = "";
	std::stringstream stream;

	if(theEnemy.getState() != Character::DEAD){
		if(theEnemy.getState() == Character::BLOODY){
			if(rand() %4 == 0){
				stream.clear();
				stream << theEnemy.getName() << " healed " << theEnemy.heal(theEnemy.getMaxHealth() / 4) << " points of health.";
				output = stream.str();
				newMessage(thePlayer, theEnemy, output, 1);
			}
			else{
				stream.clear();
				stream << thePlayer.getName() << " took " << thePlayer.takeDamage(theEnemy.attack()) << " damage!";
				output = stream.str();
				newMessage(thePlayer, theEnemy, output, 1);
				if(thePlayer.getState() == Character::DEAD){
					output = "(O,,,O) *bleh* " + thePlayer.getName() + " has died!";
					newMessage(thePlayer, theEnemy, output, 1);
				}
			}
		}
		else{
			stream.clear();
			stream << thePlayer.getName() << " took " << thePlayer.takeDamage(theEnemy.attack()) << " damage!";
			output = stream.str();
			newMessage(thePlayer, theEnemy, output, 1);
			if(thePlayer.getState() == Character::DEAD){
				output = "(O,,,O) *bleh* " + thePlayer.getName() + " has died!";
				newMessage(thePlayer, theEnemy, output, 1);
			}
		}
	}
}
/*
 * this runs when you die, just resets the map and what not for you.
 */
void Controll::resetGame(){
	std::stringstream stream;
	std::string output;
	output = "OOOH NOOOOOOO! (O,,,O) BLEEEEEH!";
	newMessageTitle(output, 7);
	stream << "You made it " << map.getFloorsCompleted() << " floors and died!";
	output = stream.str();
	newMessageTitle(output, 7);

	map.resetFloors();
	map.setUpRooms();
	setPotionsRemaining(10);
	setKeysRemaining(0);
}
/*
 * combat menu, asks what you wanna do, sends that to combat to go to turnplayer, subject to change
 */
int Controll::combatMenu(Hero &thePlayer, Enemy &theEnemy){
	int choice = 0;
	std::string buffer;
	std::string output;

	newMessage(thePlayer, theEnemy, "Time to make a move!", 1);
	std::cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "I worked really hard on these menus!";
		newMessage(thePlayer, theEnemy, output, 1);
		std::cin >> choice;
	}

	while(choice == 2 && getPotionsRemaining() <= 0){
		output = "You have no potions, choose something you CAN do.";
		newMessage(thePlayer, theEnemy, output, 1);
		std::cin >> choice;
	}

	switch(choice){
		case 1:
			output = "Attack it is!";
			newMessage(thePlayer, theEnemy, output, 1);
			break;

		case 2:
			output = "Heal it is!";
			newMessage(thePlayer, theEnemy, output, 1);
			break;

		case 3:
			output = "So... just sitting this one out? OK then.";
			newMessage(thePlayer, theEnemy, output, 1);
			break;

		default: break;
	}

	return choice;
}
/*
 * Asks if you want to move, check pack etc. sends you to appropriate menu
 */
void Controll::mapMenu(Hero &thePlayer){
	int choice;
	std::stringstream stream;
	std::string buffer;
	std::string output;

	newMessageMap(thePlayer, "What do you want to do " + thePlayer.getName() + "?", 6);
	std::cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3 && choice != 4){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "Aaaaaand nothing happens.";
		newMessageMap(thePlayer, output, 6);
		std::cin >> choice;
	}

	switch(choice){
		case 1: //try to move
			if(map.canMove()){
				moveMenu(thePlayer);
			}
			else{
				output = "Gotta murder all the stuff first.";
				newMessageMap(thePlayer, output, 6);
			}
			break;

		case 2: //check pack
			invMenu(thePlayer);
			break;

		case 3: //try to fight
			if(!map.canMove()){
				Combat(thePlayer, map.getEnemy());
			}
			else{
				output = "Listen up Conan, the room's empty. Try again!";
				newMessageMap(thePlayer, output, 6);
			}
			break;

		case 4: //try to pick up
			if(map.takeKey()){
				setKeysRemaining(getKeysRemaining() + 1);
				output = "You take the key as if it was actually yours.";
				newMessageMap(thePlayer, output, 6);
			}
			else if(map.takePotion()){
				setPotionsRemaining(getPotionsRemaining() + 1);
				output = "I'm sure drinking that wont have consequences.";
				newMessageMap(thePlayer, output, 6);
			}
			else{
				output = "Look here klepto, there's nothing useful here.";
				newMessageMap(thePlayer, output, 6);
			}
			break;
	}
}
/*
 * handles the direction you choose to move in
 */
void Controll::moveMenu(Hero & thePlayer){
	int choice;
	std::string buffer;
	std::string output;
	int currentFloor = map.getCurrentFloor();

	output = "Which direction?";
	newMessageMap(thePlayer, output, 5);
	std::cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3 && choice != 4){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "You forgot how to use menus so you sit for a while";
		newMessageMap(thePlayer, output, 5);
		std::cin >> choice;
	}

	switch(choice){
		case 1:
			if(map.canNorth()){
				map.moveNorth();
				if(map.getCurrentFloor() == currentFloor){
					if(rand()%10 != 0){
						output = "You walk north.";
					}
					else{
						output = "You hop, skip and leap north.";
					}
				}
				else{
					output = "You stumble into a new area!";
				}
			}
			else{
				output = "You run head first into a wall!";
			}
			newMessageMap(thePlayer, output, 6);
			break;

		case 2:
			if(map.canEast()){
				map.moveEast();
				if(map.getCurrentFloor() == currentFloor){
					if(rand()%10 != 0){
						output = "You walk east.";
					}
					else{
						output = "You casualy saunter east.";
					}
				}
				else{
					output = "You fell down some stairs!";
				}
			}
			else{
				output = "You say hello to the wall.";
			}
			newMessageMap(thePlayer, output, 6);
			break;

		case 3:
			if(map.canSouth()){
				map.moveSouth();
				if(map.getCurrentFloor() == currentFloor){
					if(rand()%10 != 0){
						output = "You walk south.";
					}
					else{
						output = "You slide on down south.";
					}
				}
				else{
					output = "What's this magical place?";
				}
			}
			else{
				output = "You put yourself in time out for a while.";
			}
			newMessageMap(thePlayer, output, 6);
			break;

		case 4:
			if(map.canWest()){
				map.moveWest();
				if(map.getCurrentFloor() == currentFloor){
					if(rand()%10 != 0){
						output = "You walk west.";
					}
					else{
						output = "You lazily wander west.";
					}
				}
				else{
					output = "You climb down some stairs.";
				}
			}
			else{
				output = "You give the wall a solid high-five!";
			}
			newMessageMap(thePlayer, output, 6);
			break;
		default: break;
	}

}
/*
 * displays inventory, and which item you use if you can
 */
void Controll::invMenu(Hero &thePlayer){
	int choice;
	std::string output;
	std::string buffer;

	output = "You wanna use something?";
	newMessageMap(thePlayer, output, 8);
	std::cin >> choice;

	while(choice != 1 && choice != 2 && choice != 4){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "Yeah... not a thing you can do.";
		newMessageMap(thePlayer, output, 8);
		std::cin >> choice;
	}

	while(choice == 1 && getKeysRemaining() <= 0){
		output = "You got's no keys yo!";
		newMessageMap(thePlayer, output, 8);
		std::cin >> choice;
	}

	while(choice == 2 && getPotionsRemaining() <= 0){
		output = "No potions to chug.";
		newMessageMap(thePlayer, output, 8);
		std::cin >> choice;
	}

	switch(choice){
		case 1:
			unlockMenu(thePlayer);
			break;

		case 2:
			output = "You down a potion.";
			newMessageMap(thePlayer, output, 8);
			thePlayer.heal(thePlayer.getMaxHealth() / 2);
			setPotionsRemaining(getPotionsRemaining() - 1);
			break;

		case 3:	break;

		case 4: break;

		default: break;
	}
}
/*
 * handles what happens when you use a key
 */
void Controll::unlockMenu(Hero &thePlayer){
	int choice;
	std::string buffer;
	std::string output;

	output = "Unlock which door?";
	newMessageMap(thePlayer, output, 5);
	std::cin >> choice;

	while(choice != 1 && choice != 2 && choice != 3 && choice != 4){
		std::cin.clear();
		getline(std::cin, buffer);
		output = "You dropped the key, better try again.";
		newMessageMap(thePlayer, output, 5);
		std::cin >> choice;
	}

	if(map.unlock(choice)){
		setKeysRemaining(getKeysRemaining() -1);
		output = "The key MAGICALLY unlocks the door ...and breaks?";
		newMessageMap(thePlayer, output, 8);
	}
	else{
		output = "Key in hand, you stand there as if lost.";
		newMessageMap(thePlayer, output, 8);
	}
}

bool Controll::play(Hero &thePlayer){
	if(thePlayer.getState() != Hero::DEAD){
		return true;
	}
	else{
		return false;
	}
}
/*
 * regular new message that scrolls all messages up with new messages at the bottom
 */
void Controll::newMessage(Hero &thePlayer, Enemy &theEnemy, std::string newLine, int menu){
	setLine1(getLine2());
	setLine2(getLine3());
	setLine3(getLine4());
	setLine4(newLine);
	display.drawBattle(thePlayer, theEnemy, getLine1(), getLine2(), getLine3(), getLine4(), getPotionsRemaining(), getKeysRemaining(), menu);
}
/*
 * new message with no menu options
 */
void Controll::newMessageEmpty(std::string newLine, int menu){
	setLine1(getLine2());
	setLine2(getLine3());
	setLine3(getLine4());
	setLine4(newLine);
	display.drawEmpty(getLine1(), getLine2(), getLine3(), getLine4(), getPotionsRemaining(), getKeysRemaining(), menu);
}
/*
 * new message on the title because there's no player so why send it?
 */
void Controll::newMessageTitle(std::string newLine, int menu){
	setLine1(getLine2());
	setLine2(getLine3());
	setLine3(getLine4());
	setLine4(newLine);
	display.drawTitle(getLine1(), getLine2(), getLine3(), getLine4(), getPotionsRemaining(), getKeysRemaining(), menu);
}
/*
 * display help menu messages
 */
void Controll::newMessageHelp(std::string newLine, int menu){
	setLine1(getLine2());
	setLine2(getLine3());
	setLine3(getLine4());
	setLine4(newLine);
	display.drawHelp(getLine1(), getLine2(), getLine3(), getLine4(), getPotionsRemaining(), getKeysRemaining(), menu);
}
/*
 * display credits menu messages
 */
void Controll::newMessageCredits(std::string newLine, int menu){
	setLine1(getLine2());
	setLine2(getLine3());
	setLine3(getLine4());
	setLine4(newLine);
	display.drawCredits(getLine1(), getLine2(), getLine3(), getLine4(), getPotionsRemaining(), getKeysRemaining(), menu);
}
/*
 * display Legend menu mesages
 */
void Controll::newMessageLegend(std::string newLine, int menu){
	setLine1(getLine2());
	setLine2(getLine3());
	setLine3(getLine4());
	setLine4(newLine);
	display.drawLegend(getLine1(), getLine2(), getLine3(), getLine4(), getPotionsRemaining(), getKeysRemaining(), menu);
}
/*
 * new message when your on the map, sends the string to display to display the map.
 */
void Controll::newMessageMap(Hero &thePlayer, std::string newLine, int menu){
	setLine1(getLine2());
	setLine2(getLine3());
	setLine3(getLine4());
	setLine4(newLine);
	display.drawMap(thePlayer, getLine1(), getLine2(), getLine3(), getLine4(), map.getCurrentDescription(), map.getMapString(), getPotionsRemaining(), getKeysRemaining(), menu);
}
/*
 * clears the message box
 */
void Controll::clearLines(){
	setLine1("");
	setLine2("");
	setLine3("");
	setLine4("");
}
