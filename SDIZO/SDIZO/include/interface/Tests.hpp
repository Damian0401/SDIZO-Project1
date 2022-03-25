#pragma once
#include <iostream>
#include "Timer.hpp"

namespace SDIZO
{
	class Tests
	{
	public:
		Tests(std::ostream& output);
		~Tests();
	private:
		std::ostream& output;
		SDIZO::Timer* timer;
	};
}