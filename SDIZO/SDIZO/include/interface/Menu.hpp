#pragma once

#include "Tests.hpp"
#include "Enums.hpp"

namespace SDIZO
{
	class Menu
	{
	public:
		Menu(std::string baseSourcePath,
			std::string baseResultsPath);
		~Menu();
		void run();
	private:
		Tests* tests;
		void runArrayTests();
		void runListTests();
		void runHeapTests();
		void runTreeTests();
		int getSelectedOption(MessageType messageType);
		void printMessage(MessageType messageType);
	};
}
