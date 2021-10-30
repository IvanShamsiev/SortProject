#pragma once

#include <memory>

#include "SortOperation.h"

template <typename T>
class SortAlgorithm;

enum class ESortAlgorithmType
{
	None,
	BubbleSort
};

template <typename T>
class SortingManager
{
public:
	SortingManager(ESortAlgorithmType AlgorithmType) : Results()
	{
		SetSortAlgorithm(AlgorithmType);
	}

	T* Sort(T* Array, size_t Size)
	{
		return Algorithm->Sort(Array, Size);
	}

	TArray<SortOperation<T>*>& GetResults() { return Results; };

	void PushCompare(T First, T Second, ESortCompareType Compare)
	{
		Results.Add(new CompareSortOperation<T>(First, Second, Compare));
	}

	void PushSwap(T First, T Second)
	{
		Results.Add(new SwapSortOperation<T>(First, Second));
	}

	~SortingManager()
	{
		for (auto Result : Results)
			delete Result;
	}

private:
	std::unique_ptr<SortAlgorithm<T>> Algorithm;
	TArray<SortOperation<T>*> Results;

	void SetSortAlgorithm(ESortAlgorithmType AlgorithmType)
	{
		switch(AlgorithmType)
		{
		case ESortAlgorithmType::BubbleSort:
			Algorithm = std::unique_ptr<SortAlgorithm<T>>(new BubbleSort<T>(this));
			break;
		case ESortAlgorithmType::None:
			Algorithm = nullptr;
			break;
		}
	}
};
