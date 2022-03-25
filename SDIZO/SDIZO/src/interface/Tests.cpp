#include "../../include/interface/Tests.hpp"

SDIZO::Tests::Tests(std::ostream& output) 
	: output(output), timer(new SDIZO::Timer()) {}

SDIZO::Tests::~Tests()
{
	if (this->timer != nullptr)
	{
		delete this->timer;
	}
}
