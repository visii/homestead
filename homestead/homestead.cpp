// homestead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "ioStuff.h"
#include "homestead.h"
#include "cropstuff.h"
#include "inventory.h"

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
		fieldChoiceHandler();
	}
	if (x == 3)
	{
		checkInventory();
	}
	if (x == 4)
	{
		changeActionPoints(-1);
		townOptions();
	}
	else
		invalidChoice();
}