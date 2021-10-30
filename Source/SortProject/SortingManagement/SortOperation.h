#pragma once

enum class ESortOperationType
{
	None,
	Compare,
	Swap
};

enum class ESortCompareType
{
	MoreThan,
	LessThan,
	Equals,
	NotEquals
};

template <typename T>
struct SortOperation
{
	ESortOperationType Type;
	SortOperation(ESortOperationType _Type): Type(_Type) { }
private:
	SortOperation() = delete;
};

template <typename T>
struct CompareSortOperation: SortOperation<T>
{
	T First;
	T Second;
	ESortCompareType Compare;
	CompareSortOperation(T _First, T _Second, ESortCompareType _Compare): SortOperation(ESortOperationType::Compare), First(_First), Second(_Second), Compare(_Compare) { }
	
	FString CompareToString() const
	{
		FString Value = "";
		switch(Compare)
		{
		case ESortCompareType::LessThan:
			Value = "<";
			break;
			
		case ESortCompareType::MoreThan:
			Value = ">";
			break;
			
		case ESortCompareType::Equals:
			Value = "==";
			break;
			
		case ESortCompareType::NotEquals:
			Value = "!=";
			break;
		}
		return Value;
	}
};

template <typename T>
struct SwapSortOperation: SortOperation<T>
{
	T First;
	T Second;
	SwapSortOperation(T _First, T _Second): SortOperation(ESortOperationType::Swap), First(_First), Second(_Second) { }
};