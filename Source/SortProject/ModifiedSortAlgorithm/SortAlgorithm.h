#pragma once

template <typename T>
class SortingManager;

template <typename T>
class SortAlgorithm {
public:
	SortAlgorithm(SortingManager<T>* SortingManager): Manager(SortingManager) { }
	
	virtual T* Sort(T* array, size_t size) = 0;
	
	SortingManager<T>* Manager;
};
