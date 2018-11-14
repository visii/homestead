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
		
		std::cout << "You have planted ";
		if (cropType == 0)
		{
			std::cout << "wheat.\n";
		}
		else if (cropType == 1)
		{
			std::cout << "corn.\n";
		}
		else if (cropType == 2)
		{
			std::cout << "potatos.\n";
		}
		else if (cropType == 3)
		{
			std::cout << "cabbage.\n";
		}
		else
		{
			std::cout << "ERRORZ\n";
		}
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
			<< "1) Wheat\n"
			<< "2) Corn\n"
			<< "3) Potatos\n"
			<< "4) Cabbage\n";
		int cropType{};
		std::cin >> cropType;
		return cropType;
	}

}


#endif