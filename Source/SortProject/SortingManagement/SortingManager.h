#pragma once

#include "SortOperation.h"

template <typename T>
class SortAlgorithm;

template <typename T>
class SortingManager
{
public:
	SortingManager(SortAlgorithm<T>* SortAlgorithm): Algorithm(SortAlgorithm), Results() { }
	
	SortAlgorithm<T>* Algorithm;

	TArray<SortOperation<T>*>& GetResults() { return Results; };

	void PushCompare(T First, T Second, ESortCompareType Compare)
	{
		auto op = new CompareSortOperation<T>(First, Second, Compare);
		Results.Add(op);
		UE_LOG(LogTemp, Warning, TEXT("[PushCompare] op* = %d; Result* = %d; Type = %d"), op, Results[Results.Num()-1], op->Type);
	};

	void PushSwap(T First, T Second)
	{
		auto op = new SwapSortOperation<T>(First, Second);
		Results.Add(op);
		UE_LOG(LogTemp, Warning, TEXT("[PushSwap] op* = %d; Result* = %d; Type = %d"), op, Results[Results.Num()-1], op->Type);
	};

private:
	TArray<SortOperation<T>*> Results;
};
