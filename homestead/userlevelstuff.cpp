#include "pch.h"
#include "iostuff.h"


int playerLevel(int level)
{
	static int playerLevel{ 1 };
	playerLevel = playerLevel + level;
	return playerLevel;
}

//Returns the amount of AP that should be added at the end of a turn, depending on the level of the player.
int addAP(int moreAP)
{
	static int addAPonLevelUp{ 2 };
	addAPonLevelUp = addAPonLevelUp + moreAP;
	return addAPonLevelUp;
}

//Keeps track of the XP of the player. Whenever XP is an even number, it levels up the player and resets the XP.
//Possible issues with this are that giving a player 3 XP will not levelup the player. Also it has no scaling.
//So 2 XP is enough to levelup no matter what level the player is.
int playerXP(int addXP)
{
	static int playerXP{ 0 };
	playerXP = playerXP + addXP;
	if ((playerXP % 2 == 0) && (playerXP !=0))
	{
		playerLevel(1);
		addAP(1);
		playerXP = 0;
		levelUpMessage();
	}
	return playerXP;
}
