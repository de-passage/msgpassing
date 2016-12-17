#ifndef __GUARD_SYSTEM_MANAGER_HPP__
#define __GUARD_SYSTEM_MANAGER_HPP__

#include "message_bus_aliases.hpp"

class SystemManager {
	public: 
		typedef StandardSystem SystemType;
		typedef StandardSystem::BusType BusType;

		void start(); 
		void join(); 
		void run();
		BusType::AddressType hook(SystemType&);

	private:
		std::vector<SystemType*> _threads;
		BusType _bus;
}; 


#endif

