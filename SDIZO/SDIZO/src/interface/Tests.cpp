#include "../../include/interface/Tests.hpp"
#include "../../include/SDIZO.hpp"

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

int SDIZO::Tests::getSelected(std::string header, TestsMessageType messageType)
{
	int option = -1;
	std::cout << header << std::endl;
	this->printMessage(messageType);
	std::cin >> option;
	std::cout << std::string(50, '#') << std::endl;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Failed. Selected -1 instead" << std::endl;
		return -1;
	}
	return option;
}

void SDIZO::Tests::printMessage(TestsMessageType messageType)
{
	switch (messageType)
	{
	case SDIZO::TestsMessageType::ManualArrayTestMenu:
	case SDIZO::TestsMessageType::ManualListTestMenu:
		std::cout << "1 <- addFront" << std::endl;
		std::cout << "2 <- addBack" << std::endl;
		std::cout << "3 <- addAt" << std::endl;
		std::cout << "4 <- removeFront" << std::endl;
		std::cout << "5 <- removeBack" << std::endl;
		std::cout << "6 <- removeAt" << std::endl;
		std::cout << "9 <- [read from file]" << std::endl;
		std::cout << "0 <- [exit]" << std::endl;
		break;
	case SDIZO::TestsMessageType::ManuslHeapTestMenu:
		std::cout << "1 <- add" << std::endl;
		std::cout << "2 <- removeRoot" << std::endl;
		std::cout << "9 <- [read from file]" << std::endl;
		std::cout << "0 <- [exit]" << std::endl;
		break;
	case SDIZO::TestsMessageType::ManualTreeTestMenu:
		std::cout << "1 <- add" << std::endl;
		std::cout << "2 <- remove" << std::endl;
		std::cout << "9 <- [read from file]" << std::endl;
		std::cout << "0 <- [exit]" << std::endl;
		break;
	case SDIZO::TestsMessageType::AutomaticArrayTestMenu:
		break;
	case SDIZO::TestsMessageType::AutomaticListTestMenu:
		break;
	case SDIZO::TestsMessageType::AutomaticHeapTestMenu:
		break;
	case SDIZO::TestsMessageType::AutomaticTreeTestMenu:
		break;
	case SDIZO::TestsMessageType::None:
	default:
		break;
	}
}

std::tuple<int*, int> SDIZO::Tests::getDataFromFile(std::string fileName)
{
	int dataSize = -1;
	int* dataFromFile = nullptr;

	std::ifstream sourceFile(this->baseSourcePath + fileName);

	if (sourceFile.fail())
	{
		return std::make_tuple(dataFromFile, dataSize);
	}

	sourceFile >> dataSize;

	dataFromFile = new int[dataSize];

	for (size_t i = 0; i < dataSize; i++)
	{
		sourceFile >> dataFromFile[i];
	}

	sourceFile.close();

	return std::make_tuple(dataFromFile, dataSize);
}
