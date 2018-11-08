//File that includes stuff that gets input and produces output for the user (eventually).
//For now it includes a lot of functions that will be split or moved eventually.

#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"

//Printing the stuff for the main choiceHandler function.
int printOptions()
{
	std::cout << "What would you like to do\?\n"
		<< "1) End turn\n"
		<< "2) Plant a crop\n";
		if (askCropGrowing())
		{
		std::cout   << "3) Check crop status\n"
					<< "4) Harvest crop\n";
		}
	int userChoice{};
	std::cin >> userChoice;
	return userChoice;
}

//Printing the stuff for the planting crop option.
void printPlantCrop()
{
	std::cout << "You have chosen to plant a crop.\n"
			  << "Select the type of crop you would like to plant\n"
			  << "1) Crop 1\n"
			  << "2) Crop 2\n"
			  << "3) Crop 3\n"
			  << "4) Crop 4\n";
	int cropType{};
	std::cin >> cropType;
	plantCrop(cropType);
}

//In case the user inputs a wrong number. If the user inputs a character, everything breaks.
void plantError()
{
	std::cout << "Invalid option, choose again\n";
	printPlantCrop();
}

//Function that deal with what happens when the user plants a crop.
//Shouldn't be here, but be in it's own cropstuff file.
void plantCrop(int cropType)
{
	if (cropType == 1)
	{
		std::cout << "You have planted crop1\n";
		changeCropGrowing(true);
		changePlayerMoney(-50);
		changeActionPoints(-1);
		addPlayerXP(1);
		choiceHandler();
	}
	else if (cropType == 2)
	{
		addPlayerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		std::cout << "You have planted crop2\n";
		choiceHandler();
	}
	else if (cropType == 3)
	{
		addPlayerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		std::cout << "You have planted crop3\n";
		choiceHandler();
	}
	else if (cropType == 4)
	{
		addPlayerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		std::cout << "You have planted crop4\n";
		choiceHandler(); 
	}
	
	else
		plantError();
		
}

//Incomplete function that deals with what happens when the user ends the current turn.
//So far it just resets the users action based on user level.
//Shouldn't be here, but in it's own endTurn file.
void endTurn()
{
	changeActionPoints(addAP());
	std::cout << "You have chosen to end your turn\n";
	choiceHandler();
}

//Placeholder function that deals with checking the current status of a crop (not implemented yet).
//Shouldn't be here, but in the cropStuff file.
void checkCrop()
{
	std::cout << "You have chosen to check a crop\n";
}

//Placeholer function that deals with havesting an already planted crop (not implemented yet).
//Shouldn't be here, but in the cropStuff file.
void harvestCrop()
{
	std::cout << "You have chosen to harvest a crop\n";
}

//Error in case the user inputs a wrong number.
//If the user inputs a character instead, everything breaks.
void invalidChoice()
{
	std::cout << "Invalid option, choose again\n";
	choiceHandler();
}

