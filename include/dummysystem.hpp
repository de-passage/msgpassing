#ifndef __GUARD_DUMMY_HPP__
#define __GUARD_DUMMY_HPP__

#include "threaded_system.hpp"
#include "message.hpp"
#include <chrono>
#include <iostream>

class DummySystem : public ThreadedSystem
{
	public: 
		DummySystem(const std::string& name) : _name(name) {}

		void run() {
			while(true)
			{
				if(messages()) {
					const std::string& str = read();
					if(str == "EXIT_SIGNAL")
						return;
					std::cout << _name << " received " << str << std::endl;
				}
				else {
					std::cout << _name << " didn't receive anything" << std::endl;
				}
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		} 

	private:
		const std::string& _name;
		
};

#endif
