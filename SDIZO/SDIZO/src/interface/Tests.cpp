#include "../../include/interface/Tests.hpp"

SDIZO::Tests::Tests(std::string baseSourcePath,
	std::string baseResultsPath)
	: timer(new SDIZO::Timer()), baseSourcePath(baseSourcePath),
	baseResultsPath(baseResultsPath) {}

SDIZO::Tests::~Tests()
{
	if (this->timer != nullptr)
	{
		delete this->timer;
	}
}

void SDIZO::Tests::manualArrayTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::automaticArrayTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::manualListTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::automaticListTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::manualHeapTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::automaticHeapTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::manualTreeTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::automaticTreeTest()
{
	std::cout << "TODO" << std::endl;
}

