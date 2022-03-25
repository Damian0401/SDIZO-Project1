#pragma once

#include "Tests.hpp"

namespace SDIZO
{
	class Menu
	{
	public:
		Menu(std::ostream& menuOstream, std::istream& menuIstream,
			std::ostream& testsOstream);
		~Menu();
		void run();
	private:
		Tests* tests;
		std::ostream& output;
		std::istream& input;
		void runArrayTests();
		void runListTests();
		void runHeapTests();
		void runTreeTests();
	};
}
