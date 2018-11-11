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

// Keeps track of the XP of the player. Whenever XP is equal or more than the amount of XP needed to level,
// it levels up the player. It saves any excess XP for the next level. The amount of XP needed to reach
// the next level is automatically increased as it the amount of AP the player gets back when they end
// their turn.
int playerXP(int addXP)
{
	static int levelUpTreshhold{ 2 };
	static int playerXP{ 0 };
	playerXP = playerXP + addXP;
	if ((playerXP >= levelUpTreshhold) && (playerXP !=0))
	{
		playerXP = playerXP - levelUpTreshhold;
		levelUpTreshhold++;
		playerLevel(1);
		addAP(1);
		levelUpMessage();
	}
	return playerXP;
}
