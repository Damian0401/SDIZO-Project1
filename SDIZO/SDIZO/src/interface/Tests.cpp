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

void SDIZO::Tests::manualArrayTest()
{
	Array<int>* testArray = new Array<int>();
	bool isRunning = true;
	int data = -1;
	int position = -1;
	bool success = true;

	while (isRunning)
	{
		std::cout << std::endl;
		testArray->print(std::cout);
		std::cout << std::endl;

		position = this->getSelected("Select option", TestsMessageType::ManualArrayTestMenu);

		switch (position)
		{
		case 1:
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			testArray->addFront(data);
			this->timer->stop();
			break;
		case 2:
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			testArray->addBack(data);
			this->timer->stop();
			break;
		case 3:
			position = this->getSelected("Enter position", TestsMessageType::None);
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			success = testArray->addAt(position, data);
			this->timer->stop();
			break;
		case 4:
			this->timer->start();
			success = testArray->removeFront();
			this->timer->stop();
			break;
		case 5:
			this->timer->start();
			success = testArray->removeBack();
			this->timer->stop();
			break;
		case 6:
			position = this->getSelected("Enter position", TestsMessageType::None);
			this->timer->start();
			success = testArray->removeAt(position);
			this->timer->stop();
			break;
		case 0:
			isRunning = false;
			break;
		default:
			std::cout << "Invalid option" << std::endl;
			break;
		}

		if (!success)
		{
			std::cout << "Operation failed" << std::endl;
			success = true;
		}

		std::cout << "Elapsed time: " << this->timer->getTime()
			<< "ns" << std::endl;
	}

	delete testArray;
}

void SDIZO::Tests::automaticArrayTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::manualListTest()
{
	List<int>* testList = new List<int>();
	bool isRunning = true;
	int data = -1;
	int position = -1;
	bool success = true;

	while (isRunning)
	{
		std::cout << std::endl;
		testList->print(std::cout);
		std::cout << std::endl;

		position = this->getSelected("Select option", TestsMessageType::ManualArrayTestMenu);

		switch (position)
		{
		case 1:
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			testList->addFront(data);
			this->timer->stop();
			break;
		case 2:
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			testList->addBack(data);
			this->timer->stop();
			break;
		case 3:
			position = this->getSelected("Enter position", TestsMessageType::None);
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			success = testList->addAt(position, data);
			this->timer->stop();
			break;
		case 4:
			this->timer->start();
			success = testList->removeFront();
			this->timer->stop();
			break;
		case 5:
			this->timer->start();
			success = testList->removeBack();
			this->timer->stop();
			break;
		case 6:
			position = this->getSelected("Enter position", TestsMessageType::None);
			this->timer->start();
			success = testList->removeAt(position);
			this->timer->stop();
			break;
		case 0:
			isRunning = false;
			break;
		default:
			std::cout << "Invalid option" << std::endl;
			break;
		}

		if (!success)
		{
			std::cout << "Operation failed" << std::endl;
			success = true;
		}

		std::cout << "Elapsed time: " << this->timer->getTime() 
			<< "ns" << std::endl;
	}

	delete testList;
}

void SDIZO::Tests::automaticListTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::manualHeapTest()
{
	Heap<int>* testHeap = new Heap<int>();
	bool isRunning = true;
	int data = -1;
	bool success = true;

	while (isRunning)
	{
		std::cout << std::endl;
		testHeap->print(std::cout);
		std::cout << std::endl;

		data = this->getSelected("Select option", TestsMessageType::ManuslHeapTestMenu);

		switch (data)
		{
		case 1:
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			testHeap->add(data);
			this->timer->stop();
			break;
		case 2:
			this->timer->start();
			success = testHeap->removeRoot();
			this->timer->stop();
			break;
		case 0:
			isRunning = false;
			break;
		default:
			std::cout << "Invalid option" << std::endl;
			break;
		}

		if (!success)
		{
			std::cout << "Operation failed" << std::endl;
			success = true;
		}

		std::cout << "Elapsed time: " << this->timer->getTime()
			<< "ns" << std::endl;
	}

	delete testHeap;
}

void SDIZO::Tests::automaticHeapTest()
{
	std::cout << "TODO" << std::endl;
}

void SDIZO::Tests::manualTreeTest()
{
	Tree<int>* testTree = new Tree<int>();
	bool isRunning = true;
	int data = -1;
	bool success = true;

	while (isRunning)
	{
		std::cout << std::endl;
		testTree->print(std::cout);
		std::cout << std::endl;

		data = this->getSelected("Select option", TestsMessageType::ManualTreeTestMenu);

		switch (data)
		{
		case 1:
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			testTree->add(data);
			this->timer->stop();
			break;
		case 2:
			data = this->getSelected("Enter data", TestsMessageType::None);
			this->timer->start();
			success = testTree->remove(data);
			this->timer->stop();
			break;
		case 0:
			isRunning = false;
			break;
		default:
			std::cout << "Invalid option" << std::endl;
			break;
		}

		if (!success)
		{
			std::cout << "Operation failed" << std::endl;
			success = true;
		}

		std::cout << "Elapsed time: " << this->timer->getTime()
			<< "ns" << std::endl;
	}

	delete testTree;
}

void SDIZO::Tests::automaticTreeTest()
{
	std::cout << "TODO" << std::endl;
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
		std::cout << "0 <- [exit]" << std::endl;
		break;
	case SDIZO::TestsMessageType::ManuslHeapTestMenu:
		std::cout << "1 <- add" << std::endl;
		std::cout << "2 <- removeRoot" << std::endl;
		std::cout << "0 <- [exit]" << std::endl;
		break;
	case SDIZO::TestsMessageType::ManualTreeTestMenu:
		std::cout << "1 <- add" << std::endl;
		std::cout << "2 <- remove" << std::endl;
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

