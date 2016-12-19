#include <unordered_map>

namespace detail {
	namespace messaging_policies {
	struct basic {
		typedef unsigned int AddressType;
		bool link(unsigned int, AddressType);
		inline unsigned int dereference(AddressType a) const { return a; }
	};

	template<typename T = unsigned long>
	class alias {
		public:
			typedef T AddressType;
			bool link(unsigned int, AddressType);
			unsigned int dereference(AddressType) const;
		private:
			std::unordered_map<AddressType, unsigned int> aliases;
	};

	template<typename T>
	bool alias<T>::link(unsigned int i, alias<T>::AddressType addr) {
		return aliases.insert(std::make_pair(addr, i)).second;
	}

	template<typename T>
	unsigned int alias<T>::dereference(alias<T>::AddressType addr) const {
		return aliases.at(addr); 
	}
	}
}


