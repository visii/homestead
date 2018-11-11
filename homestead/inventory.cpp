#include "pch.h"

//Function to add or remove money from the player.
int changePlayerMoney(int changeValue)
{
	static int playerMoney{ 100 };
	playerMoney = playerMoney + changeValue;
	return playerMoney;
}

