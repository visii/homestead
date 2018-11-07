#include "pch.h"
#include <iostream>
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
void plantCrop(int cropType);

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
		std::cout << "You have planted crop1";
	}
	else if (cropType == 2)
	{
		std::cout << "You have planted crop2";
	}
	else if (cropType == 3)
	{
		std::cout << "You have planted crop3";
	}
	else if (cropType == 4)
	{
		std::cout << "You have planted crop4";
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

void choiceHandler();

void invalidChoice()
{
	std::cout << "Invalid option, choose again\n";
	choiceHandler();
}


void choiceHandler()
{
	int x{ printOptions() };
	if (x == 1)
	{
		printPlantCrop();
	}
	else if (x == 2)
	{
		passTime();
	}
	else if (x == 3)
	{
		checkCrop();
	}
	else if (x == 4)
	{
		harvestCrop();
	}
	else
		invalidChoice();
}