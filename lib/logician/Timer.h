#ifndef __Timer_H__
#define __Timer_H__

#include <chrono>
#include <iostream>
#include <ctime>

namespace Utility {
	class Timer {
	public:
		Timer() : m_StartTimePoint{ std::chrono::high_resolution_clock::now()} {}

		void measureTime() {
			auto endTimePoint = std::chrono::high_resolution_clock::now();
			auto nanoDuration = endTimePoint - m_StartTimePoint;
			auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(nanoDuration);
			std::cout << milliDuration.count() << " milliseconds\n";
		}

		static std::string getCurrentTimeString() {
			time_t now_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			std::tm now_buffer;
			localtime_s(&now_buffer, &now_t);
			char date_buffer[21];
			std::strftime(date_buffer, sizeof(date_buffer), "%d/%m/%Y %H:%M:%S", &now_buffer);
			return date_buffer;
		}

		~Timer() {
			measureTime();
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
	};
}
#endif