#include "InsertSort.h"

#include "SortProject/SortingManagement/SortOperation.h"
#include "SortProject/SortingManagement/SortingManager.h"

template <typename T>
T* InsertSort<T>::Sort(T* array, size_t size) {
    for (auto i = 0; i < size; i++)
    {
        auto pos = i;
        for (auto j = i - 1; j >= 0; j--) // Find if there is number lower than current
        {
            this->Manager->PushCompare(array[i], array[j], SortCompareType::LessThan, array[i] < array[j]); // Push
            if (array[i] < array[j]) // Change this to reverse
                pos = j;
            else break;
        }
        if (pos != i) { // If need insert
            for (int j = i; j > pos; j--) // Move
            {
                this->Manager->PushSwap(array[j], array[j-1]); //Push
                std::swap(array[j], array[j-1]);
            }
        }
    }
    return array;
};