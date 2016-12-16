#ifndef __GUARD_MESSAGE_HPP__
#define __GUARD_MESSAGE_HPP__

class  Message {
	public:
		template<class T>
		Message(int i, const T& t) : type(i), obj(static_cast<const void*>(&t)) {}
		const int type;
		const void* obj;
};

#endif
