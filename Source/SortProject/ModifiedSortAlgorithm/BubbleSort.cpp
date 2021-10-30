#include "BubbleSort.h"
#include "SortProject/SortingManagement/SortingManager.h"

template <typename T>
T* BubbleSort<T>::Sort(T* array, const size_t size) {
    bool sorted = false;
    T temp;
    while (!sorted)
    {
        sorted = true;
        for (auto i = 0; i < size - 1; i++)
        {
            this->Manager->PushCompare(array[i+1], array[i], ESortCompareType::LessThan);
            if (array[i + 1] < array[i]) // Change this to reverse
            {
                sorted = false;
                this->Manager->PushSwap(array[i], array[i+1]);
                std::swap(array[i], array[i+1]);
            }
        }
    }
    return array;
};