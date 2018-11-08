// homestead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"

bool cropGrowing{ false };
int playerMoney{ 100 };
int actionPoints{ 2 };

void changeActionPoints(int changeValue)
{
	actionPoints = actionPoints + changeValue;
}

bool askCropGrowing()
{
	return cropGrowing;
}

void changeCropGrowing(bool cropStatus)
{
	cropGrowing = cropStatus;
}

void changePlayerMoney(int changeValue)
{
	playerMoney = playerMoney + changeValue;
}

int main()
{
	choiceHandler();
	return 0;
}

void choiceHandler()
{
	std::cout << "You have " << playerMoney << " moneys"
			  << " and " << actionPoints << " action points.\n";
	int x{ printOptions() };
	if (x == 1)
	{
		endTurn();
	}
	else if (x == 2)
	{
		printPlantCrop();
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