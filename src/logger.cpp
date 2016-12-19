#include <logger.hpp>

#include <chrono>
#include <ctime>
#include <iomanip>

Logger::Logger(std::ostream& out) : out(out) {
}

static void prep(std::ostream& o) {
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	o << "[" << std::put_time(&tm, "%H:%M:%S") << "] ";
}

void Logger::run() {
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		while(messages()) {
			auto m = read(); 
			if(m == Message::ExitSuccess) {
				prep(out); out << "Exit signal received" << std::endl;
				return;
			}
			else if(m == Message::ExitFailure)
			{
				prep(out); out << "Fatal error has occured" << std::endl;
				return;
			}
			else if(m.type == Message::Text) {
				prep(out); out  << m.text << std::endl;
			}
			else {
				prep(out); out << "unexpected message of type: " << m.type << std::endl;
			}
			
		}
	}
}

static void foo()
{
}
