#include "pch.h"
#include "ioStuff.h"
#include "homestead.h"

// Function to add or remove money from the player. Can also be used to ask
// how much money.
int changePlayerMoney(int changeValue)
{
	static int playerMoney{ 100 };
	playerMoney = playerMoney + changeValue;
	return playerMoney;
}

void checkInventory()
{
	printInventory();
	choiceHandler();
}