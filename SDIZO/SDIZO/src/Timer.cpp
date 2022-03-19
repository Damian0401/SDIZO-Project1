#include "../include/Timer.hpp"

void SDIZO::Timer::start()
{
	this->startPoint = std::chrono::high_resolution_clock::now();
}

void SDIZO::Timer::stop()
{
	this->endPoint = std::chrono::high_resolution_clock::now();
}

long long SDIZO::Timer::getTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(endPoint - startPoint).count();
}
