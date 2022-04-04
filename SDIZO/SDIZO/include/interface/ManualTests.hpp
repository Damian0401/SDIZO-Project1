#pragma once
#include "Tests.hpp"
#include "../Array.hpp"
#include "../List.hpp"
#include "../Heap.hpp"
#include "../Tree.hpp"

namespace SDIZO
{
	class ManualTests : public Tests
	{
	public:
		ManualTests(std::string baseSourcePath, std::string baseResultsPath);
		~ManualTests();
		void arrayTest();
		void listTest();
		void heapTest();
		void treeTest();
	private:

	};
}