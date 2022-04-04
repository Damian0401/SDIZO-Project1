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
		void manualArrayTest();
		void automaticArrayTest();
		void manualListTest();
		void automaticListTest();
		void manualHeapTest();
		void automaticHeapTest();
		void manualTreeTest();
		void automaticTreeTest();
	private:
		SDIZO::Timer* timer;
		std::string baseSourcePath;
		std::string baseResultsPath;
		int getSelected(std::string header, TestsMessageType messageType);
		void printMessage(TestsMessageType messageType);
		std::tuple<int*, int> getDataFromFile(std::string fileName);
	};
}