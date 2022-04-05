#include "../../include/interface/AutomaticTests.hpp"

SDIZO::AutomaticTests::AutomaticTests(std::string baseSourcePath, std::string baseResultsPath) 
	: Tests(baseSourcePath, baseResultsPath) {}

SDIZO::AutomaticTests::~AutomaticTests()
{
}

void SDIZO::AutomaticTests::arrayTest()
{
	int dataSize;
	int* dataFromFile;
	std::string fileName;

	std::cout << "Enter filename: ";
	std::cin >> fileName;

	std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

	if (dataFromFile == nullptr)
	{
		std::cout << "Unable to read data" << std::endl;
		return;
	}

	Array<int>* systemUnderTest = new Array<int>();

	std::ofstream addFrontResultFile(this->baseResultsPath + "array/addFront-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->addFront(dataFromFile[i]);
		this->timer->stop();
		addFrontResultFile << this->timer->getTime() << std::endl;
	}
	addFrontResultFile.close();

	std::ofstream removeFrontResultFile(this->baseResultsPath + "array/removeFront-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->removeFront();
		this->timer->stop();
		removeFrontResultFile << this->timer->getTime() << std::endl;
	}
	removeFrontResultFile.close();

	std::ofstream addBackResultFile(this->baseResultsPath + "array/addBack-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->addBack(dataFromFile[i]);
		this->timer->stop();
		addBackResultFile << this->timer->getTime() << std::endl;
	}
	addBackResultFile.close();

	std::ofstream removeBackResultFile(this->baseResultsPath + "array/removeBack-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->removeBack();
		this->timer->stop();
		removeBackResultFile << this->timer->getTime() << std::endl;
	}
	removeBackResultFile.close();

	std::ofstream addAtResultFile(this->baseResultsPath + "array/addAt-" + fileName);
	this->timer->start();
	systemUnderTest->addAt(0, dataFromFile[0]);
	this->timer->stop();
	addAtResultFile << this->timer->getTime() << std::endl;
	for (size_t i = 1; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->addAt(rand() % systemUnderTest->getSize(), dataFromFile[i]);
		this->timer->stop();
		addAtResultFile << this->timer->getTime() << std::endl;
	}
	addAtResultFile.close();

	std::ofstream removeAtResultFile(this->baseResultsPath + "array/removeAt-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->removeAt(rand() % systemUnderTest->getSize());
		this->timer->stop();
		removeAtResultFile << this->timer->getTime() << std::endl;
	}
	removeAtResultFile.close();

	std::cout << "Succeeded" << std::endl;

	delete systemUnderTest;
	delete[] dataFromFile;
}

void SDIZO::AutomaticTests::listTest()
{
	int dataSize;
	int* dataFromFile;
	std::string fileName;

	std::cout << "Enter filename: ";
	std::cin >> fileName;

	std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

	if (dataFromFile == nullptr)
	{
		std::cout << "Unable to read data" << std::endl;
		return;
	}

	List<int>* systemUnderTest = new List<int>();

	std::ofstream addFrontResultFile(this->baseResultsPath + "list/addFront-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->addFront(dataFromFile[i]);
		this->timer->stop();
		addFrontResultFile << this->timer->getTime() << std::endl;
	}
	addFrontResultFile.close();

	std::ofstream removeFrontResultFile(this->baseResultsPath + "list/removeFront-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->removeFront();
		this->timer->stop();
		removeFrontResultFile << this->timer->getTime() << std::endl;
	}
	removeFrontResultFile.close();

	std::ofstream addBackResultFile(this->baseResultsPath + "list/addBack-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->addBack(dataFromFile[i]);
		this->timer->stop();
		addBackResultFile << this->timer->getTime() << std::endl;
	}
	addBackResultFile.close();

	std::ofstream removeBackResultFile(this->baseResultsPath + "list/removeBack-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->removeBack();
		this->timer->stop();
		removeBackResultFile << this->timer->getTime() << std::endl;
	}
	removeBackResultFile.close();

	std::ofstream addAtResultFile(this->baseResultsPath + "list/addAt-" + fileName);
	this->timer->start();
	systemUnderTest->addAt(0, dataFromFile[0]);
	this->timer->stop();
	addAtResultFile << this->timer->getTime() << std::endl;
	for (size_t i = 1; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->addAt(rand() % systemUnderTest->getSize(), dataFromFile[i]);
		this->timer->stop();
		addAtResultFile << this->timer->getTime() << std::endl;
	}
	addAtResultFile.close();

	std::ofstream removeAtResultFile(this->baseResultsPath + "list/removeAt-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->removeAt(rand() % systemUnderTest->getSize());
		this->timer->stop();
		removeAtResultFile << this->timer->getTime() << std::endl;
	}
	removeAtResultFile.close();

	std::cout << "Succeeded" << std::endl;

	delete systemUnderTest;
	delete[] dataFromFile;
}



void SDIZO::AutomaticTests::heapTest()
{
	int dataSize;
	int* dataFromFile;
	std::string fileName;

	std::cout << "Enter filename: ";
	std::cin >> fileName;

	std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

	if (dataFromFile == nullptr)
	{
		std::cout << "Unable to read data" << std::endl;
		return;
	}

	Heap<int>* systemUnderTest = new Heap<int>();

	std::ofstream addResultFile(this->baseResultsPath + "heap/add-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->add(dataFromFile[i]);
		this->timer->stop();
		addResultFile << this->timer->getTime() << std::endl;
	}
	addResultFile.close();

	std::ofstream removeRootResultFile(this->baseResultsPath + "heap/removeRoot-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->removeRoot();
		this->timer->stop();
		removeRootResultFile << this->timer->getTime() << std::endl;
	}
	removeRootResultFile.close();

	std::cout << "Succeeded" << std::endl;

	delete systemUnderTest;
	delete[] dataFromFile;
}



void SDIZO::AutomaticTests::treeTest()
{
	int dataSize;
	int* dataFromFile;
	std::string fileName;

	std::cout << "Enter filename: ";
	std::cin >> fileName;

	std::tie(dataFromFile, dataSize) = this->getDataFromFile(fileName);

	if (dataFromFile == nullptr)
	{
		std::cout << "Unable to read data" << std::endl;
		return;
	}

	Tree<int>* systemUnderTest = new Tree<int>();

	std::ofstream addResultFile(this->baseResultsPath + "tree/add-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->add(dataFromFile[i]);
		this->timer->stop();
		addResultFile << this->timer->getTime() << std::endl;
	}
	addResultFile.close();

	std::ofstream removeResultFile(this->baseResultsPath + "tree/remove-" + fileName);
	for (size_t i = 0; i < dataSize; i++)
	{
		this->timer->start();
		systemUnderTest->remove(dataFromFile[i]);
		this->timer->stop();
		removeResultFile << this->timer->getTime() << std::endl;
	}
	removeResultFile.close();

	std::cout << "Succeeded" << std::endl;

	delete systemUnderTest;
	delete[] dataFromFile;
}