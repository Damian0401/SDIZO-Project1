#include <iostream>
#include "include/SDIZO.hpp"

int main()
{
	std::string sourcePath = "C:/Users/szkol/Desktop/SDIZO/projekt/SDIZO-Project1/SDIZO/SDIZO/data/";
	std::string resultsPath = "C:/Users/szkol/Desktop/SDIZO/projekt/SDIZO-Project1/SDIZO/SDIZO/results/";
	SDIZO::Menu* menu = new SDIZO::Menu(sourcePath, resultsPath);
	menu->run();
}