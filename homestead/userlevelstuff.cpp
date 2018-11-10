#include "pch.h"
#include "iostuff.h"

//Returns or changes the player level.
int playerLevel(int level)
{
	static int playerLevel{ 1 };
	playerLevel = playerLevel + level;
	return playerLevel;
}

//Returns or changes the amount of AP that should be added at the end of a turn, depending on the level of the player.
int addAP(int moreAP)
{
	static int addAPonLevelUp{ 2 };
	addAPonLevelUp = addAPonLevelUp + moreAP;
	return addAPonLevelUp;
}

//Keeps track of the XP of the player. Whenever XP is dividable by a scaling number, it levels up the player and resets the XP.
//Possible issues with this are that giving a player uneven amounts of XP will not levelup the player.
int playerXP(int addXP)
{
	static int levelUpTreshhold{ 2 };
	static int playerXP{ 0 };
	playerXP = playerXP + addXP;
	if ((playerXP % levelUpTreshhold == 0) && (playerXP !=0))
	{
		levelUpTreshhold++;
		playerLevel(1);
		addAP(1);
		playerXP = 0;
		levelUpMessage();
	}
	return playerXP;
}
