#include "../../include/interface/Menu.hpp"

SDIZO::Menu::Menu(std::string baseSourcePath,
	std::string baseResultsPath)
	: manualTests(new ManualTests(baseSourcePath, baseResultsPath)),
	automaticTests(new AutomaticTests(baseSourcePath, baseResultsPath)) {}

SDIZO::Menu::~Menu()
{
	if (this->manualTests != nullptr)
	{
		delete this->manualTests;
	}

	if (this->automaticTests != nullptr)
	{
		delete this->automaticTests;
	}
}

void SDIZO::Menu::run()
{
	bool isFinished = false;
	int selectedOption = -1;

	while (!isFinished)
	{
		selectedOption = this->getSelectedOption(MenuMessageType::MainMenu);
		switch (selectedOption)
		{
		case 1:
			this->runArrayTests();
			break;
		case 2:
			this->runListTests();
			break;
		case 3:
			this->runHeapTests();
			break;
		case 4:
			this->runTreeTests();
			break;
		case 0:
			isFinished = true;
			break;
		default:
			std::cout << "Invalid value" << std::endl;
			break;
		}
	}
}

void SDIZO::Menu::runArrayTests()
{
	int selectedOption = this->getSelectedOption(MenuMessageType::TestTypeMenu);
	switch (selectedOption)
	{
	case 1:
		this->manualTests->arrayTest();
		break;
	case 2:
		this->automaticTests->arrayTest();
		break;
	default:
		std::cout << "Invalid value" << std::endl;
		break;
	}
}

void SDIZO::Menu::runListTests()
{
	int selectedOption = this->getSelectedOption(MenuMessageType::TestTypeMenu);
	switch (selectedOption)
	{
	case 1:
		this->manualTests->listTest();
		break;
	case 2:
		this->automaticTests->listTest();
		break;
	default:
		std::cout << "Invalid value" << std::endl;
		break;
	}
}

void SDIZO::Menu::runHeapTests()
{
	int selectedOption = this->getSelectedOption(MenuMessageType::TestTypeMenu);
	switch (selectedOption)
	{
	case 1:
		this->manualTests->heapTest();
		break;
	case 2:
		this->automaticTests->heapTest();
		break;
	default:
		std::cout << "Invalid value" << std::endl;
		break;
	}
}

void SDIZO::Menu::runTreeTests()
{
	int selectedOption = this->getSelectedOption(MenuMessageType::TestTypeMenu);
	switch (selectedOption)
	{
	case 1:
		this->manualTests->treeTest();
		break;
	case 2:
		this->automaticTests->treeTest();
		break;
	default:
		std::cout << "Invalid value" << std::endl;
		break;
	}
}

int SDIZO::Menu::getSelectedOption(MenuMessageType messageType)
{
	int option = -1;
	std::cout << "Select option:" << std::endl;
	this->printMessage(messageType);
	std::cin >> option;
	std::cout << std::string(50, '#') << std::endl;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		return -1;
	}
	return option;
}

void SDIZO::Menu::printMessage(MenuMessageType messageType)
{
	switch (messageType)
	{
	case SDIZO::MenuMessageType::MainMenu:
		std::cout << "1 <- Tests for array" << std::endl;
		std::cout << "2 <- Tests for list" << std::endl;
		std::cout << "3 <- Tests for heap" << std::endl;
		std::cout << "4 <- Tests for tree" << std::endl;
		std::cout << "0 <- Exit" << std::endl;
		break;
	case SDIZO::MenuMessageType::TestTypeMenu:
		std::cout << "1 <- Manual tests" << std::endl;
		std::cout << "2 <- Automatic tests" << std::endl;
		break;
	default:
		break;
	}
}
