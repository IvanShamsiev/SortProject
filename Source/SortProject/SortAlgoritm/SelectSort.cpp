#include "SelectSort.h"

template <typename T>
T* SelectSort<T>::Sort(T* array, size_t size) {
    T temp;
    for (int i = 0; i < size; i++)
    {
        int switch_pos = i;
        for (int j = i; j < size; j++)
            if (array[j] < array[switch_pos]) // Change this to reverse
                switch_pos = j;

        // Switch
        temp = array[switch_pos];
        array[switch_pos] = array[i];
        array[i] = temp;
    }

    return array;
};