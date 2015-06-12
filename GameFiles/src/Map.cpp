/*
 * Map.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: lunarfuror
 */
#include "Map.h"

Map::Map(){
	currentFloor = 0;
	buffer = "";
	curPos[0] = 1;
	curPos[1] = 1;
	displayString = "";
	floorsCompleted = 0;

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 30; j++){
			fullMap[i][j].setTile('e');
		}
	}

	inMaps.open("maps.dat");
	if(!inMaps){
		std::cerr << "Could not read maps file!" << std::endl;
	}
	inMaps.close();

	inEnemies.open("enemies.dat");
	if(!inEnemies){
		std::cerr << "Could not read enemies file!" << std::endl;
	}
	inEnemies.close();

	inGroups.open("groups.dat");
	if(!inGroups){
		std::cerr << "Could not read groups file!" << std::endl;
	}
	inGroups.close();

	inImages.open("images.dat");
	if(!inGroups){
		std::cerr << "Could not read images file!" << std::endl;
	}
	inImages.close();

	importMaps();
	importEnemies();
	importGroups();
	importImages();
	setUpRooms();
}

//If there's no enemies in the room allow movement
bool Map::canMove(){
	if(fullMap[curPos[0]][curPos[1]].hasEnemiesLeft()){
		return false;
	}
	else
		return true;
}

//checks if North can be moved into
bool Map::canNorth(){
	if(fullMap[curPos[0]-1][curPos[1]].getTile() != 'e'
			&& fullMap[curPos[0]-1][curPos[1]].getTile() != 'O'
				 && fullMap[curPos[0]-1][curPos[1]].getTile() != 'X'
						 && fullMap[curPos[0]-1][curPos[1]].getTile() != 'L'){
		return true;
	}
	else
		return false;
}

//checks if south can be moved into
bool Map::canSouth(){
	if(fullMap[curPos[0]+1][curPos[1]].getTile() != 'e'
			&& fullMap[curPos[0]+1][curPos[1]].getTile() != 'O'
					&& fullMap[curPos[0]+1][curPos[1]].getTile() != 'X'
							&& fullMap[curPos[0]+1][curPos[1]].getTile() != 'L'){
		return true;
	}
	else
		return false;
}

//checks if east can be moved into
bool Map::canEast(){
	if(fullMap[curPos[0]][curPos[1]+1].getTile() != 'e'
			&& fullMap[curPos[0]][curPos[1]+1].getTile() != 'O'
					&& fullMap[curPos[0]][curPos[1]+1].getTile() != 'X'
							&& fullMap[curPos[0]][curPos[1]+1].getTile() != 'L'){
		return true;
	}
	else
		return false;
}

//checks if west can be moved into
bool Map::canWest(){
	if(fullMap[curPos[0]][curPos[1]-1].getTile() != 'e'
			&& fullMap[curPos[0]][curPos[1]-1].getTile() != 'O'
					&& fullMap[curPos[0]][curPos[1]-1].getTile() != 'X'
							&& fullMap[curPos[0]][curPos[1]-1].getTile() != 'L'){
		return true;
	}
	else
		return false;
}

//takes the map and turns it into a straight string the display can use
//keep this function because it calls Display tiles where as file reading
//and map vector hold raw tile chars, looks nasty. Use this string instead.
std::string Map::getMapString(){
	displayString.clear();
	MapTile thisTile;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 30; j++){
				thisTile= fullMap[i][j];
				displayString += thisTile.getDisplayTile();
			}
		}
	return displayString;
}

//Just takes the current tile's position and passes it on.
std::string Map::getCurrentDescription(){
	return fullMap[curPos[0]][curPos[1]].getDescription();
}

//takes in the current description pads or clips it, then adds on the available exits, re pads or clips.
void Map::sendExits(){
	std::string exitDesc = getCurrentDescription();
	while(exitDesc.length() < 120){
		exitDesc += " ";
	}
	exitDesc = exitDesc.substr(0, 120);

	exitDesc += "Exits Available:";

	while(exitDesc.length() < 150){
		exitDesc += " ";
	}

	if(canNorth()){
		exitDesc += "North ";
	}
	if(canEast()){
		exitDesc += "East ";
	}
	if(canSouth()){
		exitDesc += "South ";
	}
	if(canWest()){
		exitDesc += "West";
	}
	while(exitDesc.length() < 180){
		exitDesc += " ";
	}

	exitDesc = exitDesc.substr(0, 180);
	fullMap[curPos[0]][curPos[1]].setDescription(exitDesc);
}
/*
 * used to make the description random for each room. May add more as I get bored.
 * If your curious this results in 10000 possible room descriptions.
 */
std::string Map::randomDescription(){
	std::string output = "";
	std::string line1, line2, line3, line4 = "";
	switch(rand()%10){ //walls
		//formatting    :                              End
		case 0: line1 = "You see worn red brick walls, "; break;
		case 1: line1 = "You see worn grey brick walls,"; break;
		case 2: line1 = "You see smooth blue walls,    "; break;
		case 3: line1 = "You see smooth pink walls,    "; break;
		case 4: line1 = "The walls have torn paper,    "; break;
		case 5: line1 = "The walls have stripped paper,"; break;
		case 6: line1 = "The walls have dark corners,  "; break;
		case 7: line1 = "A blank card is on the wall,  "; break;
		case 8: line1 = "Large burns cover the walls,  "; break;
		case 9: line1 = "The walls are slightly damp,  "; break;
	}
	switch(rand()%10){ //floor
		//formatting    :                              End
		case 0: line2 = "the floor has blue shag carpet"; break;
		case 1: line2 = "the floor has red shag carpet,"; break;
		case 2: line2 = "burn marks riddle the floor,  "; break;
		case 3: line2 = "the floor is made of dark oak,"; break;
		case 4: line2 = "the floor is made of stones,  "; break;
		case 5: line2 = "you see blood on the floor,   "; break;
		case 6: line2 = "the floor is slightly damp,   "; break;
		case 7: line2 = "you see Pacman doing... stuff,"; break;
		case 8: line2 = "you see an orange tiled floor,"; break;
		case 9: line2 = "you see a blue tiled floor,   "; break;
	}
	switch(rand()%10){ //furniture
		//formatting    :                              End
		case 0: line3 = "and there's a pond in the room"; break;
		case 1: line3 = "there's also a large bed.     "; break;
		case 2: line3 = "you also see a giant chair.   "; break;
		case 3: line3 = "you also see a small painting."; break;
		case 4: line3 = "and there's a doggy in here!  "; break;
		case 5: line3 = "and there's a kitty in here!  "; break;
		case 6: line3 = "there are flowers everywhere. "; break;
		case 7: line3 = "a woman asks you for eggs. ;) "; break; //you know... EGGS! am i right?
		case 8: line3 = "and you hear a sweet bass line"; break;
		case 9: line3 = "there are no windows in here. "; break;
	}
	switch(rand()%10){ //how you feel about the room
		//formatting    :                              End
		case 0: line4 = "You feel at ease here.        "; break;
		case 1: line4 = "You feel someone watching you."; break;
		case 2: line4 = "This room makes you uneasy.   "; break;
		case 3: line4 = "This room reminds you of home."; break;
		case 4: line4 = "Something is not right in here"; break;
		case 5: line4 = "You feel afraid of this room. "; break;
		case 6: line4 = "The room brings you peace.    "; break;
		case 7: line4 = "You feel \"not moral\" here...  "; break;
		case 8: line4 = "The room makes your skin crawl"; break;
		case 9: line4 = "You wish you weren't in here. "; break;
	}
	output = line1 + line2 + line3 + line4;
	return output;
}
/*
 * reads in the maps.dat file to use in setting up rooms
 */
void Map::importMaps(){
	std::string thisMap;
	std::string thisEnemies;
	//buffer untill you hit ROOMS: compound strings for setting up rooms
	inMaps.open("maps.dat");
	while(!inMaps.eof()){
		//find ROOMS: flag
		while(buffer.compare("ROOMS:") != 0){
			inMaps >> buffer;
		}
		//read in and store rooms strings
		for(int i = 0; i < 8; i ++){
			inMaps >> buffer;
			thisMap += buffer;
		}
		//add map to the vector, clear the fields
		maps.push_back(thisMap);
		thisMap = "";
		buffer = "";

		//buffer until you hit ENEMIES: compound strings for enemy set up
		//find ENEMIES: flag
		while(buffer.compare("ENEMIES:") != 0){
			inMaps >> buffer;
		}
		//read in and store enemies strings
		for(int i = 0; i < 8; i ++){
			inMaps >> buffer;
			thisEnemies += buffer;
		}
		enemyMaps.push_back(thisEnemies);
		thisEnemies = "";
		buffer = "";
	}
	inMaps.close();
}

/*
 * reads enemies.dat finds alters the thisEnemy then pushes it into the enemy array.
 */
void Map::importEnemies(){
	std::string buffer = "";
	std::string name = "";
	std::string cry = "";
	int attack, speed, type, health = 1;
	double defense = 0.1;
	Enemy thisEnemy;
	inEnemies.open("enemies.dat");

	while(!inEnemies.eof()){
		//Find Name and store it
		while(buffer.compare("NAME:") != 0){
			inEnemies >> buffer;
		}
		inEnemies >> name;
		//correct '_' in name
		for(unsigned int i = 0; i < name.length() - 1; i ++){
			if(name[i] == '_'){
				name[i] = ' ';
			}
		}
		thisEnemy.setName(name);

		//find attack and store it
		while(buffer.compare("ATTACK:") != 0){
			inEnemies >> buffer;
		}
		inEnemies >> attack;
		thisEnemy.setAttack(attack);

		//find defense and store it
		while(buffer.compare("DEFENSE:") != 0){
			inEnemies >> buffer;
		}
		inEnemies >> defense;
		thisEnemy.setDefense(defense);

		//find speed and store it
		while(buffer.compare("SPEED:") != 0){
			inEnemies >> buffer;
		}
		inEnemies >> speed;
		thisEnemy.setSpeed(speed);

		//find health and store it
		while(buffer.compare("HEALTH:") != 0){
			inEnemies >> buffer;
		}
		inEnemies >> health;
		thisEnemy.setMaxHealth(health);
		thisEnemy.setCurrentHealth(health);

		//find type (used for picture) and store it
		while(buffer.compare("TYPE:") != 0){
			inEnemies >> buffer;
		}
		inEnemies >> type;
		thisEnemy.setClass(type);

		//find battle cry and store it
		while(buffer.compare("CRY:") != 0){
			inEnemies >> buffer;
		}
		inEnemies >> cry;
		//correct '_' in cry
		for(unsigned int i = 0; i < cry.length() - 1; i ++){
			if(cry[i] == '_'){
				cry[i] = ' ';
			}
		}
		thisEnemy.setBattleCry(cry);

		//put the enemy into the master group
		enemies.push_back(thisEnemy);
	}
	inEnemies.close();
	std::cout << enemies.size() << " ENEMIES LOADED" << std::endl;
}

/*
 * finds the members field, reads names and compares to existing enemy librayr, adds to groups
 */
void Map::importGroups(){
	std::string buffer = "";
	std::string name = "";
	std::vector<Enemy> groupIn;
	inGroups.open("groups.dat");

	while(!inGroups.eof()){
		//find MEMBERS: flag
		while(buffer.compare("MEMBERS:") && !inGroups.eof()){
			inGroups >> buffer;
		}
		//put members into group untill find next GROUP: flag
		while(buffer.compare("GROUP:") != 0 && !inGroups.eof()){
			inGroups >> buffer;
			//correct '_'s in name
			for(unsigned int i = 0; i < buffer.length() -1; i++){
				if(buffer[i] == '_'){
					buffer[i] = ' ';
				}
			}
			//see if enemy exists by name in the master enemies group, if yes, add to temp group
			for(int i = 0; i < enemies.size(); i++){
				if(buffer.compare(enemies.at(i).getName()) == 0){
					groupIn.push_back(enemies.at(i));
				}
			}
		}
		//add temp group to master group group to be sent to each room later
		enemyGroups.push_back(groupIn);
		//clear temp group, then loop till end
		groupIn.clear();
	}
	std::cout << enemyGroups.size() << " Groups Created" << std::endl;
}

//import images
void Map::importImages(){

}

//Incriment floor and set up rooms
void Map::nextFloor(){
	if(currentFloor < maps.size() - 1){
		currentFloor ++;
	}
	else{
		currentFloor = 0;
	}
	floorsCompleted ++;
	setUpRooms();
}

int Map::getFloorsCompleted(){
	return floorsCompleted;
}

//reset floors to 0 used when you die.
void Map::resetFloors(){
	currentFloor = 0;
}

//based on the files, run logic to set up all rooms on this floor
void Map::setUpRooms(){
	//enemy library
	std::vector<Enemy> empty;

	curPos[0] = 1;
	curPos[0] = 1;
	int tempPosX = 1;
	int tempPosY = 1;
	//reset map
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 30; j++){
			fullMap[i][j].setTile('e');
			fullMap[i][j].setHasKey(false);
			fullMap[i][j].setEnemyArray(&empty);
		}
	}

	//convert read string into map rooms
	int k = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 30; j++){
			switch(maps[currentFloor][k]){
				case 'K': fullMap[i][j].setTile('?');
					fullMap[i][j].setHasKey(true);
					break;
				case 't': fullMap[i][j].setTile(maps[currentFloor][k]);
					tempPosX = i;
					tempPosY = j;
					break;
				case 'P' : fullMap[i][j].setTile('?');
					fullMap[i][j].setHasPotion(true);
					break;
				default: fullMap[i][j].setTile(maps[currentFloor][k]); break;
			}
			if(maps[currentFloor][k] != 'e'){
				fullMap[i][j].setDescription(randomDescription());
			}
			k++;
		}
	}

	//convert read string into enemy population
	int l = 0;
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 30; j++){
			switch(enemyMaps[currentFloor][l]){
				case '1': fullMap[i][j].setEnemyArray(&enemyGroups[0]); break;
				case '2': fullMap[i][j].setEnemyArray(&enemyGroups[1]); break;
				case '3': fullMap[i][j].setEnemyArray(&enemyGroups[2]); break;
				case '4': fullMap[i][j].setEnemyArray(&enemyGroups[3]); break;
				case '5': fullMap[i][j].setEnemyArray(&enemyGroups[4]); break;
				case '6': fullMap[i][j].setEnemyArray(&enemyGroups[5]); break;
				case '7': fullMap[i][j].setEnemyArray(&enemyGroups[6]); break;
				case '8': fullMap[i][j].setEnemyArray(&enemyGroups[7]); break;
				case '9': fullMap[i][j].setEnemyArray(&enemyGroups[8]); break;
				case '0': fullMap[i][j].setEnemyArray(&enemyGroups[10]); break;
				case '!': fullMap[i][j].setEnemyArray(&enemyGroups[11]); break;
				case '@': fullMap[i][j].setEnemyArray(&enemyGroups[12]); break;
				case '#': fullMap[i][j].setEnemyArray(&enemyGroups[13]); break;
				case '$': fullMap[i][j].setEnemyArray(&enemyGroups[14]); break;
				case '%': fullMap[i][j].setEnemyArray(&enemyGroups[15]); break;
				case '^': fullMap[i][j].setEnemyArray(&enemyGroups[16]); break;
				case '&': fullMap[i][j].setEnemyArray(&enemyGroups[17]); break;
				case '*': fullMap[i][j].setEnemyArray(&enemyGroups[18]); break;
				case '(': fullMap[i][j].setEnemyArray(&enemyGroups[19]); break;
				case ')': fullMap[i][j].setEnemyArray(&enemyGroups[20]); break;
				default: break;
			}
			l++;
		}
	}

	curPos[0] = tempPosX;
	curPos[1] = tempPosY;
	enterRoom();
}

void Map::enterRoom(){
	int x = curPos[0];
	int y = curPos[1];
	char thisTile = fullMap[x][y].getTile();

	sendExits();

	fullMap[x][y].setTile('t');

	//update north
	switch(fullMap[x-1][y].getTile()){
		case 'L': fullMap[x-1][y].setTile('X');
			break;
		case 'e': fullMap[x-1][y].setTile('O');
			break;
		case 'V': fullMap[x-1][y].setTile('v');
			break;
	}

	//update south
	switch(fullMap[x+1][y].getTile()){
		case 'L': fullMap[x+1][y].setTile('X');
			break;
		case 'e': fullMap[x+1][y].setTile('O');
			break;
		case 'V': fullMap[x+1][y].setTile('v');
			break;
	}

	//update east
	switch(fullMap[x][y+1].getTile()){
		case 'L': fullMap[x][y+1].setTile('X');
			break;
		case 'e': fullMap[x][y+1].setTile('O');
			break;
		case 'V': fullMap[x][y+1].setTile('v');
			break;
	}

	//update west
	switch(fullMap[x][y-1].getTile()){
		case 'L': fullMap[x][y-1].setTile('X');
			break;
		case 'e': fullMap[x][y-1].setTile('O');
			break;
		case 'V': fullMap[x][y-1].setTile('v');
			break;
	}

	if(thisTile == 'v'){
		nextFloor();
	}
}

//Set current room to explored, move position to new room
void Map::moveNorth(){
	fullMap[curPos[0]][curPos[1]].setTile('.');
	curPos[0] -= 1;

	enterRoom();
}

//Set current room to explored, move position to new room
void Map::moveSouth(){
	fullMap[curPos[0]][curPos[1]].setTile('.');
	curPos[0] += 1;

	enterRoom();
}

//Set current room to explored, move position to new room
void Map::moveEast(){
	fullMap[curPos[0]][curPos[1]].setTile('.');
	curPos[1] += 1;

	enterRoom();
}

//Set current room to explored, move position to new room
void Map::moveWest(){
	fullMap[curPos[0]][curPos[1]].setTile('.');
	curPos[1] -= 1;

	enterRoom();
}

//Set current room to explored, move position to new room
Enemy& Map::getEnemy(){
	return fullMap[curPos[0]][curPos[1]].getNextEnemy();
}

bool Map::unlock(int direction){
	switch(direction){
		//north
		case 1:
			if(fullMap[curPos[0]-1][curPos[1]].getTile() == 'X'){
				fullMap[curPos[0]-1][curPos[1]].setTile('.');
				enterRoom();
				return true;
			}
			else{
				return false;
			}
			break;
		//east
		case 2:
			if(fullMap[curPos[0]][curPos[1]+1].getTile() == 'X'){
				fullMap[curPos[0]][curPos[1]+1].setTile('.');
				enterRoom();
				return true;
			}
			else{
				return false;
			}
			break;
		//south
		case 3:
			if(fullMap[curPos[0]+1][curPos[1]].getTile() == 'X'){
				fullMap[curPos[0]+1][curPos[1]].setTile('.');
				enterRoom();
				return true;
			}
			else{
				return false;
			}
			break;
		//west
		case 4:
			if(fullMap[curPos[0]][curPos[1] -1].getTile() == 'X'){
				fullMap[curPos[0]][curPos[1] -1].setTile('.');
				enterRoom();
				return true;
			}
			else{
				return false;
			}
			break;

		default: return false;
	}
	return false;
}

//remove key from room and return that that happened
bool Map::takeKey(){
	if(fullMap[curPos[0]][curPos[1]].getHasKey()){
		fullMap[curPos[0]][curPos[1]].setHasKey(false);
		return true;
	}
	else{
		return false;
	}
}

bool Map::takePotion(){
	if(fullMap[curPos[0]][curPos[1]].getHasPotion()){
		fullMap[curPos[0]][curPos[1]].setHasPotion(false);
		return true;
	}
	else{
		return false;
	}
}

int Map::getCurrentFloor(){
	return currentFloor;
}
