#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"


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

void plantError()
{
	std::cout << "Invalid option, choose again\n";
	printPlantCrop();
}

void plantCrop(int cropType)
{
	if (cropType == 1)
	{
		std::cout << "You have planted crop1\n";
		changeCropGrowing(true);
		changePlayerMoney(-50);
		changeActionPoints();
		choiceHandler();
	}
	else if (cropType == 2)
	{
		changeActionPoints();
		changePlayerMoney(-50);
		changeCropGrowing(true);
		std::cout << "You have planted crop2\n";
		choiceHandler();
	}
	else if (cropType == 3)
	{
		changeActionPoints();
		changePlayerMoney(-50);
		changeCropGrowing(true);
		std::cout << "You have planted crop3\n";
		choiceHandler();
	}
	else if (cropType == 4)
	{
		changeActionPoints();
		changePlayerMoney(-50);
		changeCropGrowing(true);
		std::cout << "You have planted crop4\n";
		choiceHandler(); 
	}
	
	else
		plantError();
		
}


void endTurn()
{
	std::cout << "You have chosen to end your turn\n";
}

void checkCrop()
{
	std::cout << "You have chosen to check a crop\n";
}

void harvestCrop()
{
	std::cout << "You have chosen to harvest a crop\n";
}

void invalidChoice()
{
	std::cout << "Invalid option, choose again\n";
	choiceHandler();
}

