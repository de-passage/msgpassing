#include "../include/system_manager.hpp"

#include <algorithm>

MessageBus::AddressType SystemManager::hook(ThreadedSystem& sys) {
	_threads.push_back(&sys);
	return _bus.hook(sys);
}

void SystemManager::start() {
	for_each(_threads.begin(), _threads.end(), [](auto t) { t->start(); });
}

void SystemManager::join() {
	for_each(_threads.begin(), _threads.end(), [](auto t) { t->join(); });
}

void SystemManager::run() {
	start();
	join();
}
