#include "../include/logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>

Logger::Logger(std::ostream& out) : out(out) {
}

void Logger::run() {
	while(true) {
		if(messages()) {
			std::string str = read(); 
			if(str == "EXIT_SIGNAL") {
				out << "Exit signal received" << std::endl;
				return;
			}
			else {
				auto t = std::time(nullptr);
				auto tm = *std::localtime(&t);
				out << "[" << std::put_time(&tm, "%H:%M:%S") << "] " << str << std::endl;
			}
		}
	}
}
