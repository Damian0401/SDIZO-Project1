#pragma once
#include "ManualTests.hpp"
#include "AutomaticTests.hpp"

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
		ManualTests* manualTests;
		AutomaticTests* automaticTests;
		void runArrayTests();
		void runListTests();
		void runHeapTests();
		void runTreeTests();
		int getSelectedOption(MenuMessageType messageType);
		void printMessage(MenuMessageType messageType);
	};
}
