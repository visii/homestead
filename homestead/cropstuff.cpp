#include "pch.h"

static bool cropGrowing{ false };

void changeCropGrowing(bool cropStatus)
{
	cropGrowing = cropStatus;
}

bool requestCropStatus()
{
	return cropGrowing;
}