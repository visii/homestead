#pragma once
#ifndef CRO_H
#define CRO_H

#include <iostream>
// Testing namespace stuff.
// Contains a namespace for the crop functions outputs.

namespace cro
{
	void checkCropMessage()
	{
		std::cout << "You have chosen to check a crop\n";
	}


	void harvestCropMessage()
	{
		std::cout << "You have chosen to harvest a crop\n";
	}

	void plantCropMessage(int cropType)
	{
		std::cout << "You have planted crop " << cropType << "\n";
	}
	
	void weedMessage()
	{
		std::cout << "You have chosen to weed a field\n";
	}
}


#endif