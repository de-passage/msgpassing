#ifndef __GUARD_LOGGER_HPP__
#define __GUARD_LOGGER_HPP__

#include <ostream>

#include <message_bus_aliases.hpp>

class Logger : public StandardSystem {
	public:
		Logger(std::ostream& out);
		void run();
	private:
		std::ostream& out;
};

#endif
