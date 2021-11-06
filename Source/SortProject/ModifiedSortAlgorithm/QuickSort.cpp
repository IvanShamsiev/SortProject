#include "QuickSort.h"
#include "SortProject/SortingManagement/SortOperation.h"

template <typename T>
T* QuickSort<T>::Sort(T* array, const size_t size)
{
    if (size == 2)
    {
        this->Manager->PushCompare(array[0], array[1], SortCompareType::MoreThan, array[0] > array[1]); //Push
        if (array[0] > array[1])
        {
            this->Manager->PushSwap(array[0], array[1]); //Push
            std::swap(array[0], array[1]);
        }
    }
    if (size > 2)
    {
        /*std::cout << "-sorting-" << std::endl;
        for (int i = 0; i < size; ++i)
            std::cout << array[i] << "\t";
        std::cout << std::endl;*/
        
        size_t mid = size / 2;
        this->Manager->PushCompare(array[mid], array[0], SortCompareType::LessThan, array[mid] < array[0]); //Push
        if (array[mid] < array[0])
        {
            this->Manager->PushSwap(array[0], array[mid]); //Push
            std::swap(array[0], array[mid]);
        }
        this->Manager->PushCompare(array[size-1], array[0], SortCompareType::LessThan, array[size-1] < array[0]); //Push
        if (array[size-1] < array[0])
        {
            this->Manager->PushSwap(array[0], array[size-1]); //Push
            std::swap(array[0], array[size-1]);
        }
        this->Manager->PushCompare(array[mid], array[size-1], SortCompareType::LessThan, array[mid] < array[size-1]); //Push
        if (array[mid] < array[size-1])
        {
            this->Manager->PushSwap(array[size-1], array[mid]); //Push
            std::swap(array[size-1], array[mid]);
        }
        
        T* p = array + (size-1);
        T* left = array;
        
        while (p-left > 1)
        {
            while (*left < *p)
            {
                this->Manager->PushCompare(*left, *p, SortCompareType::LessThan, *left < *p); //Push
                ++left;
            }
            this->Manager->PushCompare(*left, *p, SortCompareType::LessThan, *left < *p); //Push
            
            if (left == p || left == p-1) break;
            this->Manager->PushSwap(*left, *(p-1)); //Push
            std::swap(*left, *(p-1));
            this->Manager->PushSwap(*(p-1), *p); //Push
            std::swap(*(p-1), *p);
            --p;
        }
        this->Manager->PushCompare(*left, *p, SortCompareType::MoreThan, *left > *p); //Push
        if (*left > *p)
        {
            this->Manager->PushSwap(*left, *p); //Push
            std::swap(*left, *p--);
        }
        
        /*std::cout << "-sorted-" << std::endl;
        for (int i = 0; i < size; ++i)
            std::cout << array[i] << "\t";
        std::cout << std::endl;*/
        
        Sort(array, p - array);
        Sort(p+1, size-((p+1) - array));
    }
    return array;
}
