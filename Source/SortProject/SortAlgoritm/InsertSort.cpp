#include "InsertSort.h"

template <typename T>
T* InsertSort<T>::Sort(T* array, size_t size) {
    for (auto i = 0; i < size; i++)
    {
        auto pos = i;
        for (auto j = i - 1; j >= 0; j--) // Find if there is number lower than current
        {
            if (array[i] < array[j]) // Change this to reverse
                pos = j;
        }
        if (pos != i) { // If need insert
            T value = array[i]; // Save value
            T temp;
            for (int j = i; j > pos; j--) // Move
            {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
            array[pos] = value; // Insert
        }
    }
    return array;
};