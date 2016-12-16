#ifndef __GUARD_DUMMY_HPP__
#define __GUARD_DUMMY_HPP__

#include "hookable.hpp"
#include "message.hpp"
#include <thread>
#include <iostream>

class DummySystem : public Hookable, private std::thread
{
	public: 
		DummySystem(const std::string& name) : _name(name) {} 
		void receive(const Message& m) {
			const std::string*  str = static_cast<const std::string*>(m.obj);
			std::cout << _name << " received " << *str << std::endl;
		}

		~DummySystem() {
			if(joinable())
				join();
		}
	private:
		const std::string& _name;
		
};

#endif
