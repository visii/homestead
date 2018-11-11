#include "pch.h"
#include "ioStuff.h"
#include "homestead.h"
#include "userlevelstuff.h"
#include "inventory.h"
#include "cropstuff.h"

static bool cropGrowing{ false };

void changeCropGrowing(bool cropStatus)
{
	cropGrowing = cropStatus;
}

bool isCropGrowing()
{
	return cropGrowing;
}

//Placeholer function that deals with havesting an already planted crop (not implemented yet).
//Shouldn't be here, but in the cropStuff file.
void harvestCrop()
{
	harvestCropMessage();
	choiceHandler();
}

//Placeholder function that deals with checking the current status of a crop (not implemented yet).
//Shouldn't be here, but in the cropStuff file.
void checkCrop()
{
	checkCropMessage();
	choiceHandler();
}

void fieldChoiceHandler()
{
	int x{ printFieldOptions() };
	if (x == 1)
	{
		plantCrop();
	}
	if (x == 2)
	{
		weedField();
	}
	if (x == 3 && (isCropGrowing()))
	{
		checkCrop();
	}
	if (x == 4 && (isCropGrowing()))
	{
		harvestCrop();
	}
	else invalidChoice();
}

void weedField()
{
	weedMessage();
	choiceHandler();
}

//Function that deal with what happens when the user plants a crop.
void plantCrop()
{
	int cropType{ printPlantCrop() };
	if (cropType == 1)
	{
		plantCropMessage(1);
		changeCropGrowing(true);
		changePlayerMoney(-50);
		changeActionPoints(-1);
		playerXP(1);
		choiceHandler();
	}
	else if (cropType == 2)
	{
		plantCropMessage(2);
		playerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		choiceHandler();
	}
	else if (cropType == 3)
	{
		plantCropMessage(3);
		playerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		choiceHandler();
	}
	else if (cropType == 4)
	{
		plantCropMessage(4);
		playerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		choiceHandler();
	}

	else
		plantError();

}