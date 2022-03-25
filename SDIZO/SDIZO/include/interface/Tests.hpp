#pragma once
#include <iostream>
#include "Timer.hpp"

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
	};
}