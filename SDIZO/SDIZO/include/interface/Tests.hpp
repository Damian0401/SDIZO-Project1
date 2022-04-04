#pragma once
#include <iostream>
#include <fstream>
#include <tuple>
#include "Timer.hpp"
#include "Enums.hpp"

namespace SDIZO
{
	class Tests
	{
	public:
		Tests(std::string baseSourcePath, std::string baseResultsPath);
		~Tests();
		virtual void arrayTest() = 0;
		virtual void listTest() = 0;
		virtual void heapTest() = 0;
		virtual void treeTest() = 0;

	protected:
		SDIZO::Timer* timer;
		std::string baseSourcePath;
		std::string baseResultsPath;
		int getSelected(std::string header, TestsMessageType messageType);
		void printMessage(TestsMessageType messageType);
		std::tuple<int*, int> getDataFromFile(std::string fileName);
	};
}