/*
 * Way over Done
 * Display.cpp
 * Author: Grayson Lorenz
 * 2/21/2014
 */

#include "Display.h"
#include <sstream>
//Constructors #########################################################################
Display::Display(){
	menu = 0;
}
//getters/setters#######################################################################
void Display::setMenu(int menuType){
	menu = menuType;
}
//Do the stuff #########################################################################
/*
 * "clear"'s the screen by just spamming new lines all at once
 */
void Display::clearScreen(){
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
}
/*
 * Does the math to display the health bar correctly for whoever is sent in
 */
std::string Display::drawHealthBar(Character &theChar){
	double maxHealth = theChar.getMaxHealth();
	double health = maxHealth/20;
	double barRemaining = 20;
	std::string output = "";

	while(health <= theChar.getCurrentHealth() && barRemaining > 0){
		output += "(";
		barRemaining --;
		health = health + maxHealth/20;
	}
	while(barRemaining > 0){
		output += " ";
		barRemaining --;
	}

	return output;
}
/*
 * draw's the character name for who is sent in
 */
std::string Display::drawName(Character &theChar){
	std::string output = theChar.getName();
	while(output.length() < 16){
		output += " ";
	}
	return output;
}

std::string Display::drawLevel(Hero &thePlayer){
	std::stringstream stream;
	std::stringstream stream2;
	std::string level;

	if(thePlayer.getLevel() < 100)
		stream << "Lv: "<< thePlayer.getLevel();
	else
		stream << "**";

	level = stream.str();
	while(level.length() < 6){
		level += ' ';
	}
	level = level.substr(0, 6);

	stream2 << level << "   Exp to Level: " << (120 - thePlayer.getExperience());
	level = stream2.str();
	while(level.length() < 26){
		level += ' ';
	}
	level = level.substr(0, 26);
	return level;
}

/*
 * Draws the character's status that is passed in
 */
std::string Display::drawStatus(Character &theChar){
	std::string output = "";
	switch(theChar.getState()){
		case Character::DEAD: output = " DEAD "; break;
		case Character::BLOODY: output = "BLOODY"; break;
		case Character::NORMAL: output = "NORMAL"; break;
	}
	return output;
}
/*
 * draws the boxes holding name, hp, status, etc when in combat
 */
void Display::drawStatusBoxes(Hero &player, Character &enemy){
	std::cout << "  ____________________________________    ____________________________________  " << std::endl;
	std::cout << " /                                    \\  /                                    \\ " << std::endl;
	std::cout << "||   Name: " << drawName(player) << " [" << drawStatus(player) << "]  ||||   Name: " << drawName(enemy) << " [" << drawStatus(enemy) << "]  ||" << std::endl;
	std::cout << "||     HP: (" << drawHealthBar(player) << ")     ||||     HP: (" << drawHealthBar(enemy) << ")     ||" << std::endl;
	std::cout << "||     " << drawLevel(player) << "     ||||                                    ||" << std::endl;
	std::cout << " \\____________________________________/  \\____________________________________/ " << std::endl;
}
/*
 * display empty top 2 boxes
 */
void Display::drawStatusEmpty(){
	std::cout << "  ____________________________________    ____________________________________  " << std::endl;
	std::cout << " /                                    \\  /                                    \\ " << std::endl;
  std::cout << "||                                    ||||                                    ||" << std::endl;
  std::cout << "||                                    ||||                                    ||" << std::endl;
  std::cout << "||                                    ||||                                    ||" << std::endl;
	std::cout << " \\____________________________________/  \\____________________________________/ " << std::endl;
}
/*
 * super awesome and shiny title screen
 */
void Display::drawStatusTitle(){
	std::cout << "  ____________________________________    ____________________________________  " << std::endl;
	std::cout << " /      __             __             \\  /   _____         __                 \\ " << std::endl;
	std::cout << "||    .'  ':         .'  '.           |||| .'  | '-'     .'  ':               ||" << std::endl;
	std::cout << "||    | ompletely    | ver|done       ||||      \\ he     |   __ame  ...the    ||" << std::endl;
	std::cout << "||    '.__.:         '.__.'           ||||  '._.'        '.__.:|   assignment ||" << std::endl;
	std::cout << " \\____________________________________/  \\____________________________________/ " << std::endl;
}
/*
 * draws only the player's health and such
 */
void Display::drawStatusMap(Hero &player){
	std::cout << "  ____________________________________    ____________________________________  " << std::endl;
	std::cout << " /                                    \\  /                                    \\ " << std::endl;
	std::cout << "||   Name: " << drawName(player) << " [" << drawStatus(player) << "]  ||||                                    ||" << std::endl;
	std::cout << "||     HP: (" << drawHealthBar(player) << ")     ||||                                    ||" << std::endl;
	std::cout << "||     " << drawLevel(player) << "     ||||                                    ||" << std::endl;
	std::cout << " \\____________________________________/  \\____________________________________/ " << std::endl;
}
/*
 * holds the pictures for character and enemies.
 * also draws the middle boxes, when in combat
 * now has different versions between bloody and normal.
 */
void Display::drawPictureBoxes(Character &thePlayer, Character &theEnemy){
	std::string playerLine1 = "                              ";
	std::string playerLine2 = "                              ";
	std::string playerLine3 = "                              ";
	std::string playerLine4 = "                              ";
	std::string playerLine5 = "                              ";
	std::string playerLine6 = "                              ";
	std::string playerLine7 = "                              ";
	std::string playerLine8 = "                              ";

	std::string enemyLine1 = "                              ";
	std::string enemyLine2 = "                              ";
	std::string enemyLine3 = "                              ";
	std::string enemyLine4 = "                              ";
	std::string enemyLine5 = "                              ";
	std::string enemyLine6 = "                              ";
	std::string enemyLine7 = "                              ";
	std::string enemyLine8 = "                              ";

	switch(thePlayer.getClass()){
		case Character::WARRIOR:
			if(thePlayer.getState() == Character::NORMAL){
				playerLine1 = thePlayer.getNormalPic().substr(0,30);
				playerLine2 = thePlayer.getNormalPic().substr(30,30);
				playerLine3 = thePlayer.getNormalPic().substr(60,30);
				playerLine4 = thePlayer.getNormalPic().substr(90,30);
				playerLine5 = thePlayer.getNormalPic().substr(120,30);
				playerLine6 = thePlayer.getNormalPic().substr(150,30);
				playerLine7 = thePlayer.getNormalPic().substr(180,30);
				playerLine8 = thePlayer.getNormalPic().substr(210,30);
			}
			else{
				playerLine1 = "        /'.   /\\   .'\\        ";
				playerLine2 = "       //  '--||--'  ||       ";
				playerLine3 = "       \\      ||     /        ";
				playerLine4 = "       /      ||    |         ";
				playerLine5 = "       \\\\  .--||--. |         ";
				playerLine6 = "        \\.'   ||   '/         ";
				playerLine7 = "              )(              ";
				playerLine8 = "              ||              ";
			}
			break;

		case Character::GUARD:
			if(thePlayer.getState() == Character::NORMAL){
				playerLine1 = "            _.--._            ";
				playerLine2 = "          .'      '.          ";
				playerLine3 = "        .'   .''.   '.        ";
				playerLine4 = "       //   ///\\\\\\   \\\\       ";
				playerLine5 = "       \\\\   \\\\\\///   //       ";
				playerLine6 = "        \\\\   '..'   //        ";
				playerLine7 = "         '.        .'         ";
				playerLine8 = "           '.____.'           ";
			}
			else{
				playerLine1 = "            ______            ";
				playerLine2 = "          _|      |           ";
				playerLine3 = "        .'   .''. |___        ";
				playerLine4 = "       //   ///\\\\\\   \\\\       ";
				playerLine5 = "       \\\\   \\\\\\///   //       ";
				playerLine6 = "        \\\\   './    //        ";
				playerLine7 = "         '.  X     .'         ";
				playerLine8 = "           '._/\\_.'           ";
			}
			break;

		case Character::THEIF:
			if(thePlayer.getState() == Character::NORMAL){
				playerLine1 = "       _____________.         ";
				playerLine2 = "      /-------------|=====.   ";
				playerLine3 = "     /______________|====='   ";
				playerLine4 = "                    '         ";
				playerLine5 = "         ._____________       ";
				playerLine6 = "   .=====|-------------\\      ";
				playerLine7 = "   '=====|______________\\     ";
				playerLine8 = "         '                    ";
			}
			else{
				playerLine1 = "          __________.         ";
				playerLine2 = "      ___/----------|===._    ";
				playerLine3 = "     \\______________|====='   ";
				playerLine4 = "                              ";
				playerLine5 = "          _____  ______       ";
				playerLine6 = "   .=====|-----\\/------\\      ";
				playerLine7 = "   '=====|______________/     ";
				playerLine8 = "         '                    ";
			}
			break;
	}

	switch(theEnemy.getClass()){
		case Character::TACO:
			if(theEnemy.getState() == Character::NORMAL){
				enemyLine1 = "        S   s  S   s          ";
				enemyLine2 = "       s     S  s S           ";
				enemyLine3 = "       .------.---.           ";
				enemyLine4 = "     .' ' `  . '.xx'.         ";
				enemyLine5 = "     | . ' :  ` |%xx%|        ";
				enemyLine6 = "     | ' .  ` : |#%%#|        ";
				enemyLine7 = "     '._________'.##.'        ";
				enemyLine8 = "                              ";
			}
			else if(theEnemy.getState() == Character::BLOODY){
				enemyLine1 = "                              ";
				enemyLine2 = "                              ";
				enemyLine3 = "       .--   -.---.           ";
				enemyLine4 = "     .' ' \\ /. '.  '.         ";
				enemyLine5 = "     \\ . ' :/ ` |%xx%|        ";
				enemyLine6 = "     / ' .  ` : |#%%#|#       ";
				enemyLine7 = "     '._________'.##.'xx%     ";
				enemyLine8 = "                              ";
			}
			else if(theEnemy.getState() == Character::DEAD){
				enemyLine1 = "                              ";
				enemyLine2 = "                              ";
				enemyLine3 = "             _____            ";
				enemyLine4 = "     .----. /. '. '-.         ";
				enemyLine5 = "     | . ' V  ` |%   |        ";
				enemyLine6 = "     \\ ' .  ` : |#  #|#       ";
				enemyLine7 = "      '.________'.x_#'x%x%    ";
				enemyLine8 = "                              ";
			}
			break;

		case Character::BLOB:
			if(theEnemy.getState() == Character::NORMAL){
				enemyLine1 = "                              ";
				enemyLine2 = "             _____            ";
				enemyLine3 = "         __.'  .  '.__        ";
				enemyLine4 = "      _.' . o . O o . '._     ";
				enemyLine5 = "    .'  .  O . o O  o .  '.   ";
				enemyLine6 = "    | . . o O o .  o .  . |   ";
				enemyLine7 = "    '.___________________.'   ";
				enemyLine8 = "                              ";
			}
			else if(theEnemy.getState() == Character::BLOODY){
				enemyLine1 = "                              ";
				enemyLine2 = "                              ";
				enemyLine3 = "            __________        ";
				enemyLine4 = "        __.' . o .    '._     ";
				enemyLine5 = "      .'  .  O        o .'.   ";
				enemyLine6 = "    .' . .     o .  o .  . |  ";
				enemyLine7 = "    '.___________________.'   ";
				enemyLine8 = "                              ";
			}
			else if(theEnemy.getState() == Character::DEAD){
				enemyLine1 = "                              ";
				enemyLine2 = "                              ";
				enemyLine3 = "                              ";
				enemyLine4 = "                              ";
				enemyLine5 = "      ___________________     ";
				enemyLine6 = "    .' .   o  o     .    '.   ";
				enemyLine7 = "    '.___________________.'   ";
				enemyLine8 = "                              ";
			}
			break;

		case Character::SKELETON:
			if(theEnemy.getState() == Character::NORMAL){
				enemyLine1 = "           .-~~-.             ";
				enemyLine2 = "       _  (_O O _)            ";
				enemyLine3 = "      //    ^^^^   /^\\        ";
				enemyLine4 = "      \\\\   [[[]]]\\//^\\\\       ";
				enemyLine5 = "       \\\\ /  []  (((O)))      ";
				enemyLine6 = "        \\O. (VV)  \\\\v//       ";
				enemyLine7 = "           /    \\  \\v/        ";
				enemyLine8 = "        m()      ()m          ";
			}
			else if(theEnemy.getState() == Character::BLOODY){
				enemyLine1 = "           .-.  _             ";
				enemyLine2 = "          (_O \\/_)            ";
				enemyLine3 = "            ``^^   /^         ";
				enemyLine4 = "       /\\  [[[]]]\\//^\\        ";
				enemyLine5 = "       \\\\ /  []   ((O)        ";
				enemyLine6 = "        \\O. (VV)   \\v/        ";
				enemyLine7 = "           /    \\   v/        ";
				enemyLine8 = "        m()      ()m          ";
			}
			else if(theEnemy.getState() == Character::DEAD){
				enemyLine1 = "                              ";
				enemyLine2 = "                              ";
				enemyLine3 = "                              ";
				enemyLine4 = "                              ";
				enemyLine5 = "          /\\                  ";
				enemyLine6 = "         //.-.  _             ";
				enemyLine7 = "        //(_O \\/_)            ";
				enemyLine8 = "      O//  [[[]]]()m          ";
			}
			break;

		case Character::TACOSUPREME:
			if(theEnemy.getState() == Character::NORMAL){
				enemyLine1 = "    s   S s SS s  s S ss      ";
				enemyLine2 = "    .------------.------.     ";
				enemyLine3 = "  .' ` .   . '  : '.xXx x'.   ";
				enemyLine4 = "  | . \\ '  ` /  `  |xXOxXoX|  ";
				enemyLine5 = "  | (O _______ O). |%oXOXx%|  ";
				enemyLine6 = "  |' `/VVVVVVV\\ `  |%%oxo%%|  ";
				enemyLine7 = "  | ./_________\\ ' |##%%%##|  ";
				enemyLine8 = "  '._______________'.#####.'  ";
			}
			else if(theEnemy.getState() == Character::BLOODY){
				enemyLine1 = "      s     s  S s    s       ";
				enemyLine2 = "    __  _.-------.------.     ";
				enemyLine3 = "  .' `\\/   . '  : '.    x'.   ";
				enemyLine4 = "  | /   '  `   \\`  |x    oX|  ";
				enemyLine5 = "  | (O _______ O). |%o  Xx%|  ";
				enemyLine6 = "  |' `/       \\ `  |%% xo%%|  ";
				enemyLine7 = "  | ./_________\\ ' |##%%%##|  ";
				enemyLine8 = "  '._______________'.#####.'  ";
			}
			else if(theEnemy.getState() == Character::DEAD){
				enemyLine1 = "      s     s  S s    s       ";
				enemyLine2 = "        ____.----.___.-._     ";
				enemyLine3 = "  .---./   . '  : '.     '.   ";
				enemyLine4 = "  |    \\ ' `    `  |       |  ";
				enemyLine5 = "  | (X _______ X). |x     x|  ";
				enemyLine6 = "  |' `/       \\ `  |%    o%|  ";
				enemyLine7 = "  | .            ' |##  x##|% ";
				enemyLine8 = "  '._______________'.# ###.'Xx";
			}
			break;
	}

	std::cout << " /  ................................  \\  /  ................................  \\ " << std::endl;
		std::cout << "||  :" << playerLine1 << ":  ||||  :" << enemyLine1 << ":  ||" << std::endl;
		std::cout << "||  :" << playerLine2 << ":  ||||  :" << enemyLine2 << ":  ||" << std::endl;
		std::cout << "||  :" << playerLine3 << ":  ||||  :" << enemyLine3 << ":  ||" << std::endl;
		std::cout << "||  :" << playerLine4 << ":  ||||  :" << enemyLine4 << ":  ||" << std::endl;
		std::cout << "||  :" << playerLine5 << ":  ||||  :" << enemyLine5 << ":  ||" << std::endl;
		std::cout << "||  :" << playerLine6 << ":  ||||  :" << enemyLine6 << ":  ||" << std::endl;
		std::cout << "||  :" << playerLine7 << ":  ||||  :" << enemyLine7 << ":  ||" << std::endl;
		std::cout << "||  :" << playerLine8 << ":  ||||  :" << enemyLine8 << ":  ||" << std::endl;
		std::cout << "||  :..............................:  ||||  :..............................:  ||" << std::endl;
		std::cout << " \\____________________________________/__\\____________________________________/ " << std::endl;
}
/*
 * for now this is the title boxes
 */
void Display::drawPictureTitle(){
	std::cout << " /  ................................  \\  /  ................................  \\ " << std::endl;
	std::cout << "||  :                              :  ||||  :         version 0.3          :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :..............................:  ||||  :..............................:  ||" << std::endl;
	std::cout << " \\____________________________________/__\\____________________________________/ " << std::endl;
}
/*
 * display the help info
 */
void Display::drawPictureHelp(){
	std::cout << " /  ................................  \\  /  ................................  \\ " << std::endl;
	std::cout << "||  :        [How to Play]         :  ||||  :This box will have the map!   :  ||" << std::endl;
	std::cout << "||  :This box will have a room     :  ||||  :Use it to navigate the dungeon:  ||" << std::endl;
	std::cout << "||  :description letting you know  :  ||||  :Each floor will have enough   :  ||" << std::endl;
	std::cout << "||  :what to think about the room, :  ||||  :keys to move on to the next,  :  ||" << std::endl;
	std::cout << "||  :if there's a key in the room, :  ||||  :but some floors will have more:  ||" << std::endl;
	std::cout << "||  :how many enemies are left,    :  ||||  :keys. Be sure to explore! It  :  ||" << std::endl;
	std::cout << "||  :and if the room is PURIFIED!  :  ||||  :may make hard floors easier   :  ||" << std::endl;
	std::cout << "||  :This means you can move on!   :  ||||  :when you come to them!        :  ||" << std::endl;
	std::cout << "||  :..............................:  ||||  :..............................:  ||" << std::endl;
	std::cout << " \\____________________________________/__\\____________________________________/ " << std::endl;
}
/*
 * display the credits
 */
void Display::drawPictureCredits(){
	std::cout << " /  ................................  \\  /  ................................  \\ " << std::endl;
	std::cout << "||  : Writing     - Grayson Lorenz :  ||||  :      [ Special Thanks ]      :  ||" << std::endl;
	std::cout << "||  : Programming - Grayson Lorenz :  ||||  :    Cards Against Humanity    :  ||" << std::endl;
	std::cout << "||  : Enemy Art   - Grayson Lorenz :  ||||  :   Music albums  on Youtube   :  ||" << std::endl;
	std::cout << "||  : Director    - Grayson Lorenz :  ||||  : His Highness, Grayson Lorenz :  ||" << std::endl;
	std::cout << "||  : Producer    - Grayson Lorenz :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  : UI Design   - Grayson Lorenz :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  : Credits by  - Grayson Lorenz :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :        Grayson Lorenz        :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :..............................:  ||||  :..............................:  ||" << std::endl;
	std::cout << " \\____________________________________/__\\____________________________________/ " << std::endl;
}
/*
 * display the legend and generic map
 */
void Display::drawPictureLegend(){
	std::cout << " /  ................................  \\  /  ................................  \\ " << std::endl;
	std::cout << "||  :          [Legend]            :  ||||  :             [Map]            :  ||" << std::endl;
	std::cout << "||  :  t - You!                    :  ||||  :          O                   :  ||" << std::endl;
	std::cout << "||  :  O - Walls                   :  ||||  :        OOtOOO                :  ||" << std::endl;
	std::cout << "||  :  X - Locked Door             :  ||||  :       Ok  X  v               :  ||" << std::endl;
	std::cout << "||  :  k - Key left in room        :  ||||  :        OO OOO                :  ||" << std::endl;
	std::cout << "||  :  v - goes to next floor      :  ||||  :         OkO                  :  ||" << std::endl;
	std::cout << "||  :   there's no going back      :  ||||  :          O                   :  ||" << std::endl;
	std::cout << "||  :    to a previous floor       :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :..............................:  ||||  :..............................:  ||" << std::endl;
	std::cout << " \\____________________________________/__\\____________________________________/ " << std::endl;
}
/*
 * display classInfo!
 */
void Display::drawPictureClass(){
	std::cout << " /  ................................  \\  /  ................................  \\ " << std::endl;
	std::cout << "||  : Warrior - Average attack     :  ||||  : Assassin- High attack, low   :  ||" << std::endl;
	std::cout << "||  : and defense, low crit chance.:  ||||  : defense, high crit chance.   :  ||" << std::endl;
	std::cout << "||  : Average speed and health.    :  ||||  : High speed lower health.     :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  : Guard - Low attack, high     :  ||||  : Hidden 4th option - there is :  ||" << std::endl;
	std::cout << "||  : defense, and health, but slow:  ||||  : no hidden 4th option I'm not :  ||" << std::endl;
	std::cout << "||  : average crit chance          :  ||||  : that deep. This isnt FFVII!  :  ||" << std::endl;
	std::cout << "||  :                              :  ||||  :                              :  ||" << std::endl;
	std::cout << "||  :..............................:  ||||  :..............................:  ||" << std::endl;
	std::cout << " \\____________________________________/__\\____________________________________/ " << std::endl;
}
/*
 * grabs the string from the map class, then displays the map and description, this method is fun
 */
void Display::drawPictureMap(std::string description, std::string mapString){
	while(description.length() < 240){
			description += " ";
	}

	while(mapString.length() < 240){
		mapString += " ";
	}

	std::array<std::string, 8> descArray;
	std::array<std::string, 8> mapArray;

	for(int i = 0; i < 8; i++){
		descArray[i] = description.substr(i*30, 30);
	}

	for(int i = 0; i < 8; i++){
		mapArray[i] = mapString.substr(i*30, 30);
	}

	std::cout << " /  ................................  \\  /  ................................  \\ " << std::endl;
	std::cout << "||  :" << descArray[0] << ":  ||||  :" << mapArray[0] << ":  ||" << "\n";
	std::cout << "||  :" << descArray[1] << ":  ||||  :" << mapArray[1] << ":  ||" << "\n";
	std::cout << "||  :" << descArray[2] << ":  ||||  :" << mapArray[2] << ":  ||" << "\n";
	std::cout << "||  :" << descArray[3] << ":  ||||  :" << mapArray[3] << ":  ||" << "\n";
	std::cout << "||  :" << descArray[4] << ":  ||||  :" << mapArray[4] << ":  ||" << "\n";
	std::cout << "||  :" << descArray[5] << ":  ||||  :" << mapArray[5] << ":  ||" << "\n";
	std::cout << "||  :" << descArray[6] << ":  ||||  :" << mapArray[6] << ":  ||" << "\n";
	std::cout << "||  :" << descArray[7] << ":  ||||  :" << mapArray[7] << ":  ||" << "\n";
	std::cout << "||  :..............................:  ||||  :..............................:  ||" << std::endl;
	std::cout << " \\____________________________________/__\\____________________________________/ " << std::endl;
}
/*
 * luckily display and controll do most of the work here, but displays 4 lines, and the menu
 */
void Display::drawMenuBoxes(std::string line1, std::string line2, std::string line3, std::string line4, int potions, int keys, int menu){
	line1 = line1.substr(0,50);
	line2 = line2.substr(0,50);
	line3 = line3.substr(0,50);
	line4 = line4.substr(0,50);
	if(potions > 99){
		potions = 99;
	}
	if(keys > 99){
		keys = 99;
	}

	std::stringstream stream;

	std::string menu1 = "";
	std::string menu2 = "";
	std::string menu3 = "";
	std::string menu4 = "";

	switch(menu){
		case 0: //confirm yes or no
			menu1 = " 1. Yes";
			menu2 = " 2. No";
			menu3 = "";
			menu4 = "";
			break;

		case 1: // battle menu
			menu1 = " 1. ATTAAAACK!";

			if(potions > 9){
				stream.str("");
				stream << " 2. Potion(" << potions << ")";
				menu2 = stream.str();
			}
			else{
				stream.str("");
				stream << " 2. Potion(0" << potions << ")";
				menu2 = stream.str();
			}

			menu3 = " 3. Do nothing";
			menu4 = "";
			break;

		case 2: // continue / new character
			menu1 = " 1. Continue";
			menu2 = " 2. New / Quit";
			menu3 = "";
			menu4 = "";
			break;

		case 3: // new Character / quit
			menu1 = " 1. New Char.";
			menu2 = " 2. Quit";
			menu3 = "";
			menu4 = "";
			break;

		case 4: // choose class
			menu1 = " 1. Warrior!";
			menu2 = " 2. Guard!";
			menu3 = " 3. Assassin!";
			menu4 = "";
			break;

		case 5: // directions
				menu1 = " 1. North / ^";
				menu2 = " 2. East  / >";
				menu3 = " 3. South / v";
				menu4 = " 4. West  / <";
			break;

		case 6: //overworld
			menu1 = " 1. Move";
			menu2 = " 2. Pack";
			menu3 = " 3. Fight";
			menu4 = " 4. Pick Up";
			break;

		case 7: //blank
			menu1 = "";
			menu2 = "";
			menu3 = "";
			menu4 = "";
			break;

		case 8:
			//keys menu1
			stream.str("");
			if(keys > 9){
				stream << " 1. Key   (" << keys << ")";
				menu1 = stream.str();
			}
			else{
				stream << " 1. Key   (0" << keys << ")";
				menu1 = stream.str();
			}

			//potions menu2
			stream.str("");
			if(potions > 9){
				stream << " 2. Potion(" << potions << ")";
				menu2 = stream.str();
			}
			else{
				stream << " 2. Potion(0" << potions << ")";
				menu2 = stream.str();
			}

			menu3 = "";
			menu4 = " 4. Close Pack";
			break;

		case 9: //intro menu
			menu1 = "1. Begin";
			menu2 = "2. Help";
			menu3 = "3. Credits";
			menu4 = "4. Quit";
			break;

		case 10: //blank
			menu1 = "1. Return";
			menu2 = "2. Legend";
			menu3 = "";
			menu4 = "";
			break;

		case 11: //blank
			menu1 = "1. Return";
			menu2 = "";
			menu3 = "";
			menu4 = "";
			break;
	}

	while(menu1.length() < 15){
		menu1 += " ";
	}
	while(menu2.length() < 15){
		menu2 += " ";
	}
	while(menu3.length() < 15){
		menu3 += " ";
	}
	while(menu4.length() < 15){
		menu4 += " ";
	}

	while(line1.length() < 50){
		line1 += " ";
	}
	while(line2.length() < 50){
		line2 += " ";
	}
	while(line3.length() < 50){
		line3 += " ";
	}
	while(line4.length() < 50){
		line4 += " ";
	}

	std::cout << " /                     [Message]                        \\ /      [Menu]       \\ " << std::endl;
	std::cout << "|| [" << line1 << "] ||| [" << menu1 << "] ||" << std::endl;
	std::cout << "|| [" << line2 << "] ||| [" << menu2 << "] ||" << std::endl;
	std::cout << "|| [" << line3 << "] ||| [" << menu3 << "] ||" << std::endl;
	std::cout << "|| [" << line4 << "] ||| [" << menu4 << "] ||" << std::endl;
	std::cout << " \\______________________________________________________/ \\___________________/ " << std::endl;
	std::cout << "What do:";
#ifdef WINDOWS_OS
	Sleep(1);
#else
	sleep(1);
#endif
}
/*
 * over arching refresh just runs all the sub methods to make the whole screen happen
 */
void Display::drawBattle(Hero &thePlayer, Character &theEnemy, std::string line1, std::string line2, std::string line3, std::string line4, int potions, int keys, int menu){
	clearScreen();
	drawStatusBoxes(thePlayer, theEnemy);
	drawPictureBoxes(thePlayer, theEnemy);
	drawMenuBoxes(line1, line2, line3, line4, potions, keys, menu);
}
/*
 * over arching refresh just runs all the sub methods to make the whole screen happen
 */
void Display::drawEmpty(std::string line1, std::string line2, std::string line3, std::string line4, int potions, int keys, int menu){
	clearScreen();
	drawStatusEmpty();
	drawPictureClass();
	drawMenuBoxes(line1, line2, line3, line4, potions, keys, menu);
}
/*
 * over arching refresh just runs all the sub methods to make the whole screen happen
 */
void Display::drawTitle(std::string line1, std::string line2, std::string line3, std::string line4, int potions, int keys, int menu){
	clearScreen();
	drawStatusTitle();
	drawPictureTitle();
	drawMenuBoxes(line1, line2, line3, line4, potions, keys, menu);
}
/*
 * over arching refresh just runs all the sub methods to make the whole screen happen
 */
void Display::drawHelp(std::string line1, std::string line2, std::string line3, std::string line4, int potions, int keys, int menu){
	clearScreen();
	drawStatusTitle();
	drawPictureHelp();
	drawMenuBoxes(line1, line2, line3, line4, potions, keys, menu);
}
/*
 * over arching refresh just runs all the sub methods to make the whole screen happen
 */
void Display::drawCredits(std::string line1, std::string line2, std::string line3, std::string line4, int potions, int keys, int menu){
	clearScreen();
	drawStatusTitle();
	drawPictureCredits();
	drawMenuBoxes(line1, line2, line3, line4, potions, keys, menu);
}
/*
 * over arching refresh just runs all the sub methods to make the whole screen happen
 */
void Display::drawLegend(std::string line1, std::string line2, std::string line3, std::string line4, int potions, int keys, int menu){
	clearScreen();
	drawStatusTitle();
	drawPictureLegend();
	drawMenuBoxes(line1, line2, line3, line4, potions, keys, menu);
}
/*
 * over arching refresh just runs all the sub methods to make the whole screen happen
 */
void Display::drawMap(Hero &thePlayer, std::string line1, std::string line2, std::string line3, std::string line4,std::string description, std::string map,  int potions, int keys ,int menu){
	clearScreen();
	drawStatusMap(thePlayer);
	drawPictureMap(description, map);
	drawMenuBoxes(line1, line2, line3, line4, potions, keys, menu);
}
