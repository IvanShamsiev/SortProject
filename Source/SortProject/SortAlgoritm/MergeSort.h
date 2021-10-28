#pragma once

#include "SortAlgorithm.h"
#include <vector>

template <typename T>
class MergeSort : public SortAlgorithm<T>
{
public:
	virtual T* Sort(T* array, size_t size) override;

	std::vector<T>& Sort(std::vector<T>& vector);

private:
	
	//T* merge(int first_size, T* first_array, int second_size, T* second_array);
	T* merge(T* begin, T* middle, T* end);


	void vector_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end);

	void vector_merge(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator middle, typename std::vector<T>::iterator end);
};
