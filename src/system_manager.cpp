#include "../include/system_manager.hpp"

#include <algorithm>

SystemManager::BusType::AddressType SystemManager::hook(SystemManager::SystemType& sys, BusType::AddressType add) {
	_threads.push_back(&sys);
	return _bus.hook(sys, add);
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
