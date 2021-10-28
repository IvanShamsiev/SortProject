#include "QuickSort.h"

#include <iostream>

template <typename T>
T* QuickSort<T>::Sort(T* array, const size_t size)
{
    if (size == 2 && array[0] > array[1])
        std::swap(array[0], array[1]);
    if (size > 2)
    {
        /*std::cout << "-sorting-" << std::endl;
        for (int i = 0; i < size; ++i)
            std::cout << array[i] << "\t";
        std::cout << std::endl;*/
        
        size_t mid = size / 2;
        if (array[mid] < array[0])
            std::swap(array[0], array[mid]);
        if (array[size-1] < array[0])
            std::swap(array[0], array[size-1]);
        if (array[mid] < array[size-1])
            std::swap(array[size-1], array[mid]);
        
        T* p = array + (size-1);
        T* left = array;
        
        while (p-left > 1)
        {
            while (*left < *p) ++left;
            if (left == p) break;
            std::swap(*left, *(p-1));
            std::swap(*(p-1), *p);
            --p;
        }
        if (*left > *p) std::swap(*left, *p--);
        
        /*std::cout << "-sorted-" << std::endl;
        for (int i = 0; i < size; ++i)
            std::cout << array[i] << "\t";
        std::cout << std::endl;*/
        
        Sort(array, p - array);
        Sort(p+1, size-((p+1) - array));
    }
    return array;
}