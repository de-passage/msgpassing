#include <algorithm>
#include <vector>

#include "../include/messagebus.hpp"
#include "../include/dummysystem.hpp"


int main()
{
	MessageBus mb; 
	DummySystem ds1("Dummy 1");
	DummySystem ds2("Dummy 2");
	mb.hook(&ds1);
	mb.hook(&ds2);
	ds1.start();
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	ds2.start();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	mb.send("test", 1);
	ds1.join();
	ds2.join();

	return 0;
}
