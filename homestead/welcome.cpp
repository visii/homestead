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

void welcomeMsgName()
{
	std::cout << "Welcome to homestead!\n";
	std::string userName{ returnUserName() };
	std::cout << "Hello " << userName << "!\n";
}

void welcomeMsgFarm()
{

}