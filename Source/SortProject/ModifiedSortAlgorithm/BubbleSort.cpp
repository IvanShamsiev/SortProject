#include "BubbleSort.h"
#include "SortProject/SortingManagement/SortOperation.h"

template <typename T>
T* BubbleSort<T>::Sort(T* array, const size_t size) {
    bool sorted = false;
    T temp;
    while (!sorted)
    {
        sorted = true;
        for (auto i = 0; i < size - 1; i++)
        {
            this->Manager->PushCompare(array[i+1], array[i], SortCompareType::LessThan, array[i+1] < array[i]); //Push
            if (array[i+1] < array[i]) // Change this to reverse
            {
                sorted = false;
                this->Manager->PushSwap(array[i], array[i+1]); //Push
                std::swap(array[i], array[i+1]);
            }
        }
    }
    return array;
}