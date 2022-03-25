#include <iostream>
#include "include/SDIZO.hpp"

int main()
{
	std::string sourcePath = "C:/put/here/absolute/path/to/source/directory";
	std::string resultsPath = "C:/put/here/absolute/path/to/results/directory";
	SDIZO::Menu* menu = new SDIZO::Menu(sourcePath, resultsPath);
	menu->run();
}