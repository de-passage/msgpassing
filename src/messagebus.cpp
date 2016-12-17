#include "../include/messagebus.hpp"

#include "../include/hookable.hpp"

#include <algorithm>
#include <stdexcept>

namespace detail {
	namespace messaging_policies {
		bool basic::link(unsigned int, basic::AddressType) {
			return false;
		}

		bool alias::link(unsigned int i, alias::AddressType addr) {
			return aliases.insert(std::make_pair(addr, i)).second;
		}

		unsigned int alias::dereference(alias::AddressType addr) const {
			return aliases.at(addr); 
		}
	}
}
