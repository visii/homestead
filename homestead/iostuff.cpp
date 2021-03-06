//File that includes stuff that gets input and produces output for the user (eventually).
//For now it includes a lot of functions that will be split or moved eventually.

#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"
#include "cropstuff.h"
#include "userlevelstuff.h"
#include "inventory.h"
#include "townstuff.h"
#include "welcome.h"

void levelUpMessage()
{
	std::cout << "Congratulations " << returnUserName() 
			  << " you have levelled up!\n"
			  << "You are now level " << playerLevel(0) << "\n";
}

//Prints the current status of the player
void printStatus()
{
	std::cout << "You have " << changePlayerMoney(0) << " moneys"
		<< " and " << changeActionPoints(0) << " action points.\n"
		<< "You are level " << playerLevel(0)
		<< " and you have " << playerXP(0) << " experience.\n";
}

void printInventory()
{
	std::cout << "Your inventory is emtpy\n";
}

void genStoreMsg()
{
	std::cout << "You are in the general store\n";
}
void toolStoreMsg()
{
	std::cout << "You are in the tool store\n";
}
void lsStoreMsg()
{
	std::cout << "You are at the livestock market\n";
}


int printTownOptions()
{
	std::cout << "You arrived in town. What would do you like to do\?\n"
			  << "1) Visit the livestock market\n"
			  << "2) Go to the general store\n"
			  << "3) Go to the tool store\n";
	int userChoice{};
	std::cin >> userChoice;
	return userChoice;
}

//Printing the stuff for the main choiceHandler function.
int printOptions()
{
	std::cout << "You are at the " << returnFarmName() << "\n"
			  << "What would you like to do\?\n"
			  << "1) End turn\n"
			  << "2) Go to your fields\n"
			  << "3) Check your inventory\n"
			  << "4) Go to town (1 ap)\n";
	int userChoice{};
	std::cin >> userChoice;
	return userChoice;
}

//In case the user inputs a wrong number. If the user inputs a character, everything breaks.
void plantError()
{
	std::cout << "Invalid option, choose again\n";
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	plantCrop();
}

void townError()
{
	std::cout << "Invalid option, choose again\n";
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	townOptions();
}

//Incomplete function that deals with what happens when the user ends the current turn.
//So far it just resets the users action based on user level.
//Shouldn't be here, but in it's own endTurn file.
void endTurn()
{
	changeActionPoints(addAP(0));
	std::cout << "You have chosen to end your turn\n"
			  << "Because you are level " << playerLevel(0)
			  << " you have gained " << addAP(0) << " AP\n\n";
	choiceHandler();
}


//Error in case the user inputs a wrong number.
//If the user inputs a character instead, everything breaks.
void invalidChoice()
{
	std::cout << "Invalid option, choose again\n";
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	choiceHandler();
}

