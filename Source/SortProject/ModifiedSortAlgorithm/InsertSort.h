#pragma once

#include "SortAlgorithm.h"

template <typename T>
class InsertSort : public SortAlgorithm<T> {
public:
	InsertSort(SortingManager<T>* SortingManager): SortAlgorithm(SortingManager) { }
	
	virtual T* Sort(T* array, size_t size) override;
};