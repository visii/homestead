// homestead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"

//bool cropGrowing{ false };
//int playerMoney{ 100 };
//int actionPoints{ 2 };
int playerXP{ 0 };
int playerLevel{ 1 };
int addAPonLevelUp{ 2 };


//Returns the amount of AP that should be added at the end of a turn, depending on the level of the player.
int addAP()
{
	return addAPonLevelUp;
}

//Keeps track of the XP of the player. Whenever XP is an even number, it levels up the player and resets the XP.
//Possible issues with this are that giving a player 3 XP will not levelup the player. Also it has no scaling.
//So 2 XP is enough to levelup no matter what level the player is.
void addPlayerXP(int addXP)
{
	playerXP = playerXP + addXP;
	if (playerXP % 2 == 0)
	{
		playerLevel++;
		addAPonLevelUp++;
		playerXP = 0;
	}
}

//Removes or adds and returns action points. Called whenever the user takes an action.
int changeActionPoints(int changeValue)
{
	static int actionPoints{ 2 };			// Testing static variables.
	actionPoints = actionPoints + changeValue;
	return actionPoints;
}

//Returns whether there's currently a crop growing or not. To determine what menu options to display.
//bool askCropGrowing()
//{
//	return cropGrowing;
//}

//Function to keep track of whether there currently is a crop planted and growing. 
//Not working properly so far, cause it can only keep track of one crop, not several.
//void changeCropGrowing(bool cropStatus)
//{
//	cropGrowing = cropStatus;
//}

//Function to add or remove money from the player.
int changePlayerMoney(int changeValue)
{
	static int playerMoney{ 100 };
	playerMoney = playerMoney + changeValue;
	return playerMoney;
}

int main()
{
	choiceHandler();
	return 0;
}

//Main function to deal with user input.
void choiceHandler()
{
	std::cout << "You have " << changePlayerMoney(0) << " moneys"
			  << " and " << changeActionPoints(0) << " action points.\n"
			  << " You are level " << playerLevel
			  << " and you have " << playerXP << " experience.\n";
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