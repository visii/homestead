//File that includes stuff that gets input and produces output for the user (eventually).
//For now it includes a lot of functions that will be split or moved eventually.

#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"
#include "cropstuff.h"
#include "userlevelstuff.h"
#include "inventory.h"

void levelUpMessage()
{
	std::cout << "Congratulations!\n"
			  << "You have levelled up!\n"
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

//Printing the stuff for the main choiceHandler function.
int printOptions()
{
	std::cout << "What would you like to do\?\n"
			  << "1) End turn\n"
			  << "2) Go to your fields\n";
	int userChoice{};
	std::cin >> userChoice;
	return userChoice;
}

int printFieldOptions()
{
	std::cout << "You are at your fields. What would you like to do\?\n"
			  << "1) Plant a crop\n"
			  << "2) Weed a field\n";
		if (isCropGrowing())
		{
			std::cout << "3) Check crop status\n"
					  << "4) Harvest crop\n";
		}
	int userChoice{};
	std::cin >> userChoice;
	return userChoice;
}

//Printing the stuff for the planting crop option.
int printPlantCrop()
{
	std::cout << "You have chosen to plant a crop.\n"
			  << "Select the type of crop you would like to plant\n"
			  << "1) Crop 1\n"
			  << "2) Crop 2\n"
			  << "3) Crop 3\n"
			  << "4) Crop 4\n";
	int cropType{};
	std::cin >> cropType;
	return cropType;
}

//In case the user inputs a wrong number. If the user inputs a character, everything breaks.
void plantError()
{
	std::cout << "Invalid option, choose again\n";
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	plantCrop();
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

