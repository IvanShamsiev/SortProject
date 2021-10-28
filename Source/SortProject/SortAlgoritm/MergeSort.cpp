#pragma once

#include "MergeSort.h"
#include <iostream>
#include <vector>

template <typename T>
T* MergeSort<T>::Sort(T* array, size_t size)
{

	if (size > 1)
	{
		size_t left_size = size / 2;
		size_t right_size = left_size;
		if (size % 2 != 0) ++right_size;

		T* left_array = Sort(&array[0], left_size);
		T* right_array = Sort(&array[left_size], right_size);

		/*std::cout << "-- merge --" << std::endl;
		std::cout << "_left array_" << std::endl;
		for (int i = 0; i < left_size; i++)
			std::cout << left_array[i] << std::endl;
		std::cout << "right array_" << std::endl;
		for (int i = 0; i < right_size; i++)
			std::cout << right_array[i] << std::endl;*/

		// May be "array = merge(..)", but no need, cuz "left"/"right" array are parts of "array" and we just working with pointers
		//merge(left_size, left_array, right_size, right_array);
		merge(left_array, right_array, right_array + right_size);


		/*std::cout << "-- after merge array --" << std::endl;
		for (int i = 0; i < size; i++)
			std::cout << array[i] << std::endl;

		std::cout << std::endl;*/
	}

	return array;
}

/*
template <typename T>
T* MergeSort<T>::merge(int first_size, T* first_array, int second_size, T* second_array)
{
	T* merge_array = new T[first_size + second_size];

	int first_pos = 0, second_pos = 0;
	for (int i = 0; i < first_size + second_size; i++)
	{
		if (first_pos == first_size)
		{
			for (int j = second_pos; j < second_size; j++)
				merge_array[i + (j - second_pos)] = second_array[j];
			break;
		}
		if (second_pos == second_size)
		{
			for (int j = first_pos; j < first_size; j++)
				merge_array[i + (j - first_pos)] = first_array[j];
			break;
		}

		if (first_array[first_pos] < second_array[second_pos]) // Change this to reverse
			merge_array[i] = first_array[first_pos++];
		else
			merge_array[i] = second_array[second_pos++];
	}

	for (int i = 0; i < first_size + second_size; i++)
	{
		if (i < first_size) first_array[i] = merge_array[i];
		else second_array[i - first_size] = merge_array[i];
	}

	delete[] merge_array;
	return first_array;
}*/

template <typename T>
T* MergeSort<T>::merge(T* begin, T* middle, T* end)
{
	T* merge_array = new T[end-begin];

	T* merge_pos = merge_array;
	T* left = begin;
	T* right = middle;
	while (merge_pos != merge_array + (end - begin))
	{
		if (left == middle)
		{
			while (right != end)
				*merge_pos++ = *right++;
			break;
		}
		if (right == end)
		{
			while (left != middle)
				*merge_pos++ = *left++;
			break;
		}

		if (*left < *right) // Change this to reverse
			*merge_pos++ = *left++;
		else
			*merge_pos++ = *right++;
	}

	merge_pos = merge_array;
	T* temp_begin = begin;
	while (temp_begin != end)
		*temp_begin++ = *merge_pos++;

	delete[] merge_array;
	return begin;
}


/**
 *	Sorting the vector
 *
 *	@vector - we sorting it
 *	@returns link for the sorted @vector
 */
template <typename T>
std::vector<T>& MergeSort<T>::Sort(std::vector<T>& vector)
{
	vector_sort(vector.begin(), vector.end());

	return vector;
}


template <typename T>
void MergeSort<T>::vector_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
	int size = end - begin;
	if (size > 1)
	{
		int left_size = size / 2;

		vector_sort(begin, begin + left_size);
		vector_sort(begin + left_size, end);

		// May be "array = merge(..)", but no need, cuz "left"/"right" array are parts of "array" and we just working with pointers
		vector_merge(begin, begin + left_size, end);
	}
}

template <typename T>
void MergeSort<T>::vector_merge(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator middle, typename std::vector<T>::iterator end)
{
	std::vector<T> merge_vector(end - begin);
	auto left = begin;
	auto right = middle;

	auto merge_iter = merge_vector.begin();
	while (merge_iter != merge_vector.end())
	{
		if (left == middle)
		{
			std::move(right, end, merge_iter);
			break;
		}
		if (right == end)
		{
			std::move(left, middle, merge_iter);
			break;
		}

		if (*left < *right) // Change this to reverse
			*merge_iter++ = *left++;
		else
			*merge_iter++ = *right++;
	}

	std::move(merge_vector.begin(), merge_vector.end(), begin);
}