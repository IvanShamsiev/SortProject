#pragma once

#include "SortAlgorithm.h"

template <typename T>
class QuickSort : public SortAlgorithm<T>
{
public:
	QuickSort(SortingManager<T>* SortingManager): SortAlgorithm(SortingManager) { }
	
    virtual T* Sort(T* array, size_t size) override;

private:
    //T* quick_sort(T* array, size_t size);
    //T* get_middle(T* array, const size_t size);
};
