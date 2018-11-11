// homestead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "ioStuff.h"
#include "homestead.h"
#include "cropstuff.h"

//Removes or adds and returns action points. Called whenever the user takes an action.
int changeActionPoints(int changeValue)
{
	static int actionPoints{ 2 };			
	actionPoints = actionPoints + changeValue;
	return actionPoints;
}

int main()
{
	choiceHandler();
	return 0;
}

//Main function to deal with user input.
void choiceHandler()
{
	printStatus();
	int x{ printOptions() };
	if (x == 1)
	{
		endTurn();
	}
	if (x == 2)
	{
		printPlantCrop();
	}
	if (x == 3 && (isCropGrowing()))
	{
		checkCrop();
	}
	if (x == 4 && (isCropGrowing()))
	{
		harvestCrop();
	}
	else
		invalidChoice();
}