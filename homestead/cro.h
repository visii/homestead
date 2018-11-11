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
	
	int printFieldOptions()
	{
		std::cout << "You are at your fields. What would you like to do\?\n"
			<< "1) Plant a crop\n"
			<< "2) Weed a field\n";
		if (isCropGrowing())
		{
			std::cout << "3) Check crop status\n"
				<< "4) Harvest crop\n";
		}
		int userChoice{};
		std::cin >> userChoice;
		return userChoice;
	}

	//Printing the stuff for the planting crop option.
	int printPlantCrop()
	{
		std::cout << "You have chosen to plant a crop.\n"
			<< "Select the type of crop you would like to plant\n"
			<< "1) Crop 1\n"
			<< "2) Crop 2\n"
			<< "3) Crop 3\n"
			<< "4) Crop 4\n";
		int cropType{};
		std::cin >> cropType;
		return cropType;
	}

}


#endif