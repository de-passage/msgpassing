#ifndef __GUARD_LOGGER_HPP__
#define __GUARD_LOGGER_HPP__

#include <ostream>

#include "../include/threaded_system.hpp"

class Logger : public ThreadedSystem {
	public:
		Logger(std::ostream& out);
		void run();
	private:
		std::ostream& out;
};

#endif
