// homestead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "ioStuff.h"
#include "homestead.h"
#include "cropstuff.h"
#include "inventory.h"
#include "welcome.h"

// Removes or adds and returns action points. Called whenever the user takes an action.
// that requires actionpoints
int changeActionPoints(int changeValue)
{
	static int actionPoints{ 2 };			
	actionPoints = actionPoints + changeValue;
	return actionPoints;
}

int main()
{
	welcomeMenu();
	return 0;
}

// Welcomes the user and gets their name and the name of their farm.
void welcomeMenu()
{
	welcomeMsgName();
	welcomeMsgFarm();
	choiceHandler();
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