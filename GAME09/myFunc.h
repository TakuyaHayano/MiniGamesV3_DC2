#pragma once
#include <vector>

template <typename T>
void safe_clear(std::vector<T*>& vec) {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		delete (*it);
	}
	vec.clear();
}