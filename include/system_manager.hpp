#ifndef __GUARD_SYSTEM_MANAGER_HPP__
#define __GUARD_SYSTEM_MANAGER_HPP__

#include "threaded_system.hpp"
#include "messagebus.hpp"

class SystemManager {
	public: 
		void start(); 
		void join(); 
		void run();
		MessageBus::AddressType hook(ThreadedSystem&);

	private:
		std::vector<ThreadedSystem*> _threads;
		MessageBus _bus;
}; 


#endif

