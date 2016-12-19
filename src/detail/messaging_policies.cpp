#include <messaging_policies.hpp>

namespace detail {
	namespace messaging_policies {
		bool basic::link(unsigned int, basic::AddressType) {
			return false;
		}
	}
}

