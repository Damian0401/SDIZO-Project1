#pragma once

#include <chrono>

namespace SDIZO
{
	class Timer
	{
	public:
		void start();
		void stop();
		long long getTime();
	private:
		std::chrono::high_resolution_clock::time_point startPoint;
		std::chrono::high_resolution_clock::time_point endPoint;
	};
}
