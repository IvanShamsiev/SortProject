#pragma once

template <typename T>
class SortAlgorithm {
public:
	virtual T* Sort(T* array, size_t size) = 0;
};