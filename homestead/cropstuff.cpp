#include "pch.h"
#include "ioStuff.h"
#include "homestead.h"
#include "userlevelstuff.h"
#include "inventory.h"
#include "cropstuff.h"
#include "cro.h"

// This global variable can only be changed by 1 function, changeCropGrowing. 
// Other functions needing it's status can do so with the isCropGrowing bool.
// Apart from those 2 functions, no other functions interact with it.
static bool cropGrowing{ false };

// Function that can change the status of cropGrowing, changes when the user plants or
// harvest crops. Issues with this method are that it cannot keep track of how many
// crop are growing. So harvesting just 1 crop while 3 are growing will set this to
// false.
void changeCropGrowing(bool cropStatus)
{
	cropGrowing = cropStatus;
}

// Bool that keeps track of if a crop is currently growing;
bool isCropGrowing()
{
	return cropGrowing;
}

//Placeholer function that deals with havesting an already planted crop (not implemented yet).
//Shouldn't be here, but in the cropStuff file.
void harvestCrop()
{
	cro::harvestCropMessage();
	choiceHandler();
}

//Placeholder function that deals with checking the current status of a crop (not implemented yet).
void checkCrop()
{
	cro::checkCropMessage();
	choiceHandler();
}


// Main function that deals with the option a user chooses if he visit the fields.
void fieldChoiceHandler()
{
	int x{ cro::printFieldOptions() };
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

// Placeholder function that deals with weeding a field (not implemented yet).
void weedField()
{
	cro::weedMessage();
	choiceHandler();
}

// Function that deal with what happens when the user plants a crop.
// It removes the appropiate amount of money and action points for the chosen
// crop and adds the appropiate amount of XP.
void plantCrop()
{
	int cropType{ cro::printPlantCrop() };
	if (cropType == 1)
	{
		cro::plantCropMessage(CropTypes::WHEAT);
		changeCropGrowing(true);
		changePlayerMoney(-50);
		changeActionPoints(-1);
		playerXP(1);
		choiceHandler();
	}
	else if (cropType == 2)
	{
		cro::plantCropMessage(CropTypes::CORN);
		playerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		choiceHandler();
	}
	else if (cropType == 3)
	{
		cro::plantCropMessage(CropTypes::POTATO);
		playerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		choiceHandler();
	}
	else if (cropType == 4)
	{
		cro::plantCropMessage(CropTypes::CABBAGE);
		playerXP(1);
		changeActionPoints(-1);
		changePlayerMoney(-50);
		changeCropGrowing(true);
		choiceHandler();
	}

	else
		plantError();

}