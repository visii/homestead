#include "pch.h"
#include <string>
#include <iostream>

std::string askUserName()
{
	std::cout << "Please enter your name ";
	std::string userName{};
	std::getline(std::cin, userName);
	return userName;
}

std::string returnUserName()
{
	static std::string userName{ askUserName() };
	return userName;
}

std::string askFarmName()
{
	std::cout << "Please enter the name of your farm ";
	std::string farmName{};
	std::getline(std::cin, farmName);
	return farmName;
}

std::string returnFarmName()
{
	static std::string farmName{ askFarmName() };
	return farmName;
}

void welcomeMsgName()
{
	std::cout << "Welcome to homestead!\n";
	std::string userName{ returnUserName() };
	std::cout << "Hello " << userName << "!\n";
}

void welcomeMsgFarm()
{
	std::string userName{ returnFarmName() };
	std::cout << "Your farm is now called " << userName << "!\n";
}