#include "BubbleSort.h"

template <typename T>
T* BubbleSort<T>::Sort(T* array, const size_t size) {
    bool sorted = false;
    T temp;
    while (!sorted)
    {
        sorted = true;
        for (auto i = 0; i < size - 1; i++)
        {
            if (array[i + 1] < array[i]) // Change this to reverse
            {
                sorted = false;
                //std::swap(array[i], array[i+1]);
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    return array;
};