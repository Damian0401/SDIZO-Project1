#include "../../include/interface/Menu.hpp"

SDIZO::Menu::Menu(std::ostream& menuOstream,
	std::istream& menuIstream, std::ostream& testsOstream) 
		: tests(new Tests(testsOstream)), output(menuOstream),
		input(menuIstream) {}

SDIZO::Menu::~Menu()
{
	if (this->tests != nullptr)
	{
		delete this->tests;
	}
}

void SDIZO::Menu::run()
{
	bool isFinished = false;
	int selectedOption = -1;

	while (!isFinished)
	{
		this->output << std::string(50, '#') << std::endl;
		this->output << "Select option:" << std::endl;
		this->input >> selectedOption;

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
		default:
			isFinished = true;
			break;
		}
	}
}

void SDIZO::Menu::runArrayTests()
{
	this->output << "There will be array tests implementation" << std::endl;
}

void SDIZO::Menu::runListTests()
{
	this->output << "There will be list tests implementation" << std::endl;
}

void SDIZO::Menu::runHeapTests()
{
	this->output << "There will be heap tests implementation" << std::endl;
}

void SDIZO::Menu::runTreeTests()
{
	this->output << "There will be tree tests implementation" << std::endl;
}
