#include "pch.h"
#include "ioStuff.h"
#include "homestead.h"

static bool cropGrowing{ false };
void weedField();

void changeCropGrowing(bool cropStatus)
{
	cropGrowing = cropStatus;
}

bool isCropGrowing()
{
	return cropGrowing;
}

void fieldChoiceHandler()
{
	int x{ printFieldOptions() };
	if (x == 1)
	{
		printPlantCrop();
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