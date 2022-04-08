#include "../../include/interface/ManualTests.hpp"

SDIZO::ManualTests::ManualTests(std::string baseSourcePath, std::string baseResultsPath)
	: Tests(baseSourcePath, baseResultsPath) {}

SDIZO::ManualTests::~ManualTests()
{
}

void SDIZO::ManualTests::arrayTest()
{
	Array<int>* testArray = new Array<int>();
	int dataSize;
	int* dataFromFile;
	std::string fileName;
	bool isRunning = true;
	bool success = true;
	int data = -1;
	int position = -1;

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
		case 9:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

			if (dataFromFile == nullptr)
			{
				std::cout << "Unable to read data" << std::endl;
				continue;
			}

			for (size_t i = 0; i < dataSize; i++)
			{
				testArray->addBack(dataFromFile[i]);
			}

			delete dataFromFile;
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

void SDIZO::ManualTests::listTest()
{
	List<int>* testList = new List<int>();
	int dataSize;
	int* dataFromFile;
	std::string fileName;
	bool isRunning = true;
	bool success = true;
	int data = -1;
	int position = -1;

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
		case 9:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

			if (dataFromFile == nullptr)
			{
				std::cout << "Unable to read data" << std::endl;
				continue;
			}

			for (size_t i = 0; i < dataSize; i++)
			{
				testList->addBack(dataFromFile[i]);
			}

			delete dataFromFile;
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

void SDIZO::ManualTests::heapTest()
{
	Heap<int>* testHeap = new Heap<int>();
	int dataSize;
	int* dataFromFile;
	std::string fileName;
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
		case 9:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

			if (dataFromFile == nullptr)
			{
				std::cout << "Unable to read data" << std::endl;
				continue;
			}

			for (size_t i = 0; i < dataSize; i++)
			{
				testHeap->add(dataFromFile[i]);
			}

			delete dataFromFile;
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

void SDIZO::ManualTests::treeTest()
{
	Tree<int>* testTree = new Tree<int>();
	int dataSize;
	int* dataFromFile;
	std::string fileName;
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
		case 9:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

			if (dataFromFile == nullptr)
			{
				std::cout << "Unable to read data" << std::endl;
				continue;
			}

			for (size_t i = 0; i < dataSize; i++)
			{
				testTree->add(dataFromFile[i]);
			}

			delete dataFromFile;
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