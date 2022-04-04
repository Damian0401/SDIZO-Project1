#pragma once
#include "Tests.hpp"
#include "../Array.hpp"
#include "../List.hpp"
#include "../Heap.hpp"
#include "../Tree.hpp"

namespace SDIZO
{
	class AutomaticTests : public Tests
	{
	public:
		AutomaticTests(std::string baseSourcePath, std::string baseResultsPath);
		~AutomaticTests();
		void arrayTest();
		void listTest();
		void heapTest();
		void treeTest();
	private:

	};
}