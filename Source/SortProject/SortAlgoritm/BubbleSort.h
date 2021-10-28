#pragma once

#include "SortAlgorithm.h"

template <typename T>
class BubbleSort : public SortAlgorithm<T> {
public:
	virtual T* Sort(T* array, size_t size) override;
};