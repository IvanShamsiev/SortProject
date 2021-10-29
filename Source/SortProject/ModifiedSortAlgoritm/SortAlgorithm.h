#pragma once

template <typename T>
class SortAlgorithm {
public:
	virtual T* Sort(T* array, size_t size, TFunction<void(T*, size_t, TFunction<void()>)> Process) = 0;
};