// homestead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ioStuff.h"
#include "homestead.h"

bool cropGrowing{ false };

int main()
{
	choiceHandler();
	return 0;
}

void choiceHandler()
{
	int x{ printOptions() };
	if (x == 1)
	{
		printPlantCrop();
	}
	else if (x == 2)
	{
		passTime();
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