#pragma once

#include <memory>

#include "SortOperation.h"
#include "SortProject/ModifiedSortAlgorithm/BubbleSort.h"
#include "SortProject/ModifiedSortAlgorithm/InsertSort.h"
#include "SortProject/ModifiedSortAlgorithm/QuickSort.h"

template <typename T>
class SortAlgorithm;

enum class ESortAlgorithmType
{
	None,
	BubbleSort,
	QuickSort,
	InsertSort
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

	void PushCompare(T First, T Second, SortCompareType Compare, bool CompareSuccess)
	{
		Results.Add(new CompareSortOperation<T>(First, Second, Compare, CompareSuccess));
	}

	void PushSwap(T First, T Second)
	{
		Results.Add(new SwapSortOperation<T>(First, Second));
	}

	void PushCreateTemp(unsigned int TempId, size_t TempSize)
	{
		Results.Add(new CreateTempOperation<T>(TempId, TempSize));
	}

	void PushRemoveTemp(unsigned int TempId)
	{
		Results.Add(new RemoveTempOperation<T>(TempId));
	}

	void PushCopyToTemp(T Movable, unsigned int TempId, size_t TempPosition)
	{
		Results.Add(new CopyToTempOperation<T>(Movable, TempId, TempPosition));
	}

	void PushCopyFromTemp(T Movable, unsigned int TempId, size_t ArrayPosition)
	{
		Results.Add(new CopyFromTempOperation<T>(Movable, TempId, ArrayPosition));
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
		case ESortAlgorithmType::QuickSort:
			Algorithm = std::unique_ptr<SortAlgorithm<T>>(new QuickSort<T>(this));
			break;
		case ESortAlgorithmType::InsertSort:
			Algorithm = std::unique_ptr<SortAlgorithm<T>>(new InsertSort<T>(this));
			break;
		case ESortAlgorithmType::None:
			Algorithm = nullptr;
			break;
		}
	}
};
