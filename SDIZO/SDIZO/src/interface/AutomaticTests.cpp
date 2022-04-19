#include <vector>
#include <numeric>
#include <string>
#include "../../include/interface/AutomaticTests.hpp"

SDIZO::AutomaticTests::AutomaticTests(std::string baseSourcePath, std::string baseResultsPath) 
	: Tests(baseSourcePath, baseResultsPath) 
{
	srand(time(nullptr));
}

SDIZO::AutomaticTests::~AutomaticTests()
{
}

void SDIZO::AutomaticTests::arrayTest()
{
	Array<int>* systemUnderTests = nullptr;

	int dataNumber = this->getSelected("Enter number of data", TestsMessageType::None);
	int repeats = this->getSelected("Enter number of repeats", TestsMessageType::None);
	int maxDataSize = this->getSelected("Enter maximum data size", TestsMessageType::None);

	if (dataNumber < 10 && maxDataSize < 10)
	{
		std::cout << "Invalid initial data" << std::endl;
		return;
	}

	std::ofstream resultFile(this->baseResultsPath + "array/" + std::to_string(dataNumber) + "-results.txt");

	std::vector<int> addResults;
	addResults.reserve(dataNumber);
	std::vector<int> removeResults;
	removeResults.reserve(dataNumber);
	std::vector<int> searchResults;
	searchResults.reserve(dataNumber);
	int valueToAdd = -1;
	int valueToSearch = -1;

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new Array<int>();
		
		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			valueToAdd = rand() % (maxDataSize + 1);
			systemUnderTests->addFront(valueToAdd);
			if (i == dataNumber / 2)
			{
				valueToSearch = valueToAdd;
			}
		}
		
		this->timer->start();
		systemUnderTests->addFront(rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());
		
		this->timer->start();
		systemUnderTests->search(valueToSearch);
		this->timer->stop();
		searchResults.push_back(this->timer->getTime());
		
		this->timer->start();
		systemUnderTests->removeFront();
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());
		
		delete systemUnderTests;
	}

	resultFile << "Array: search, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << std::endl;
	resultFile << "Array: addFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats 
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "Array: removeFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats 
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	addResults.clear();
	removeResults.clear();
	searchResults.clear();

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new Array<int>();

		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			systemUnderTests->addFront(rand() % (maxDataSize + 1));
		}

		this->timer->start();
		systemUnderTests->addBack(rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->removeBack();
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());

		delete systemUnderTests;
	}

	resultFile << "Array: addBack, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "Array: removeBack, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	addResults.clear();
	removeResults.clear();

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new Array<int>();

		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			systemUnderTests->addFront(rand() % (maxDataSize + 1));
		}

		this->timer->start();
		systemUnderTests->addAt(rand() % systemUnderTests->getSize(), rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->removeAt(rand() % systemUnderTests->getSize());
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());

		delete systemUnderTests;
	}

	resultFile << "Array: addAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "Array: removeAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	resultFile.close();
}

void SDIZO::AutomaticTests::listTest()
{
	List<int>* systemUnderTests = nullptr;

	int dataNumber = this->getSelected("Enter number of data", TestsMessageType::None);
	int repeats = this->getSelected("Enter number of repeats", TestsMessageType::None);
	int maxDataSize = this->getSelected("Enter maximum data size", TestsMessageType::None);

	if (dataNumber < 10 && maxDataSize < 10)
	{
		std::cout << "Invalid initial data" << std::endl;
		return;
	}

	std::ofstream resultFile(this->baseResultsPath + "list/" + std::to_string(dataNumber) + "-results.txt");

	std::vector<int> addResults;
	addResults.reserve(dataNumber);
	std::vector<int> removeResults;
	removeResults.reserve(dataNumber);
	std::vector<int> searchResults;
	searchResults.reserve(dataNumber);
	int valueToAdd = -1;
	int valueToSearch = -1;

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new List<int>();

		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			valueToAdd = rand() % (maxDataSize + 1);
			systemUnderTests->addFront(valueToAdd);
			if (i == dataNumber / 2)
			{
				valueToSearch = valueToAdd;
			}
		}

		this->timer->start();
		systemUnderTests->addFront(rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->search(valueToSearch);
		this->timer->stop();
		searchResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->removeFront();
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());

		delete systemUnderTests;
	}

	resultFile << "List: search, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << std::endl;
	resultFile << "List: addFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "List: removeFront, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	addResults.clear();
	removeResults.clear();
	searchResults.clear();

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new List<int>();

		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			systemUnderTests->addFront(rand() % (maxDataSize + 1));
		}

		this->timer->start();
		systemUnderTests->addBack(rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->removeBack();
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());

		delete systemUnderTests;
	}

	resultFile << "List: addBack, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "List: removeBack, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	addResults.clear();
	removeResults.clear();

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new List<int>();

		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			systemUnderTests->addFront(rand() % (maxDataSize + 1));
		}

		this->timer->start();
		systemUnderTests->addAt(rand() % systemUnderTests->getSize(), rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->removeAt(rand() % systemUnderTests->getSize());
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());

		delete systemUnderTests;
	}

	resultFile << "List: addAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "List: removeAt, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	resultFile.close();
}



void SDIZO::AutomaticTests::heapTest()
{
	Heap<int>* systemUnderTests = nullptr;

	int dataNumber = this->getSelected("Enter number of data", TestsMessageType::None);
	int repeats = this->getSelected("Enter number of repeats", TestsMessageType::None);
	int maxDataSize = this->getSelected("Enter maximum data size", TestsMessageType::None);

	if (dataNumber < 10 && maxDataSize < 10)
	{
		std::cout << "Invalid initial data" << std::endl;
		return;
	}

	std::ofstream resultFile(this->baseResultsPath + "heap/" + std::to_string(dataNumber) + "-results.txt");

	std::vector<int> addResults;
	addResults.reserve(dataNumber);
	std::vector<int> removeResults;
	removeResults.reserve(dataNumber);
	std::vector<int> searchResults;
	searchResults.reserve(dataNumber);
	int valueToAdd = -1;
	int valueToSearch = -1;

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new Heap<int>();

		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			valueToAdd = rand() % (maxDataSize + 1);
			systemUnderTests->add(valueToAdd);
			if (i == dataNumber / 2)
			{
				valueToSearch = valueToAdd;
			}
		}

		this->timer->start();
		systemUnderTests->add(rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->search(valueToSearch);
		this->timer->stop();
		searchResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->removeRoot();
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());

		delete systemUnderTests;
	}

	resultFile << "Heap: search, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << std::endl;
	resultFile << "Heap: add, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "Heap: removeRoot, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	resultFile.close();
}



void SDIZO::AutomaticTests::treeTest()
{
	Tree<int>* systemUnderTests = nullptr;

	int dataNumber = this->getSelected("Enter number of data", TestsMessageType::None);
	int repeats = this->getSelected("Enter number of repeats", TestsMessageType::None);
	int maxDataSize = this->getSelected("Enter maximum data size", TestsMessageType::None);

	if (dataNumber < 10 && maxDataSize < 10)
	{
		std::cout << "Invalid initial data" << std::endl;
		return;
	}

	std::ofstream resultFile(this->baseResultsPath + "tree/" + std::to_string(dataNumber) + "-results.txt");

	std::vector<int> addResults;
	addResults.reserve(dataNumber);
	std::vector<int> removeResults;
	removeResults.reserve(dataNumber);
	std::vector<int> searchResults;
	searchResults.reserve(dataNumber);
	int valueToAdd = -1;
	int valueToSearch = -1;

	for (size_t i = 0; i < repeats; i++)
	{
		systemUnderTests = new Tree<int>();

		for (size_t i = 0; i < dataNumber - 1; i++)
		{
			valueToAdd = rand() % (maxDataSize + 1);
			systemUnderTests->add(valueToAdd);
			if (i == dataNumber / 2)
			{
				valueToSearch = valueToAdd;
			}
		}

		this->timer->start();
		systemUnderTests->add(rand() % (maxDataSize + 1));
		this->timer->stop();
		addResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->search(valueToSearch);
		this->timer->stop();
		searchResults.push_back(this->timer->getTime());

		this->timer->start();
		systemUnderTests->remove(valueToSearch);
		this->timer->stop();
		removeResults.push_back(this->timer->getTime());

		delete systemUnderTests;
	}

	resultFile << "Tree: search, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(searchResults.begin(), searchResults.end(), 0) / searchResults.size()) << std::endl;
	resultFile << "Tree: add, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(addResults.begin(), addResults.end(), 0) / addResults.size()) << std::endl;
	resultFile << "Tree: remove, data range: 0 - " << maxDataSize << ", repeats: " << repeats
		<< ", average time: " << (std::accumulate(removeResults.begin(), removeResults.end(), 0) / removeResults.size()) << std::endl;

	resultFile.close();
}