#include <algorithm>
#include <vector>

#include "../include/messagebus.hpp"
#include "../include/dummysystem.hpp"


int main(int argc, char* argv[])
{
	MessageBus mb; 
	DummySystem ds1("Dummy 1");
	DummySystem ds2("Dummy 2");
	mb.hook(&ds1);
	mb.hook(&ds2);
	Message msg(0, std::string("test"));
	mb.send(msg, 1);

	return 0;
}
