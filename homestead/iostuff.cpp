#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"


int printOptions()
{
	std::cout << "What would you like to do\?\n"
		<< "1) Plant crop\n"
		<< "2) Pass time\n"
		<< "3) Check crop status\n"
		<< "4) Harvest crop\n";
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
		changePlayerMoney(-50);
		choiceHandler();
	}
	else if (cropType == 2)
	{
		changePlayerMoney(-50);
		std::cout << "You have planted crop2\n";
		choiceHandler();
	}
	else if (cropType == 3)
	{
		changePlayerMoney(-50);
		std::cout << "You have planted crop3\n";
		choiceHandler();
	}
	else if (cropType == 4)
	{
		changePlayerMoney(-50);
		std::cout << "You have planted crop4\n";
		choiceHandler(); 
	}
	
	else
		plantError();
		
}


void passTime()
{
	std::cout << "You have chosen to pass time";
}

void checkCrop()
{
	std::cout << "You have chosen to check a crop";
}

void harvestCrop()
{
	std::cout << "You have chosen to harvest a crop";
}

void invalidChoice()
{
	std::cout << "Invalid option, choose again\n";
	choiceHandler();
}

