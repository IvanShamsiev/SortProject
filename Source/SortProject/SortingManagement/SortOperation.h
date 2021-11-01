#pragma once

enum class SortOperationType
{
	None,
	Compare,
	Swap
};

enum class SortCompareType
{
	None,
	MoreThan,
	LessThan,
	Equals,
	NotEquals
};

template <typename T>
struct SortOperation
{
	SortOperationType Type;
	SortOperation(SortOperationType _Type): Type(_Type) { }
private:
	SortOperation() = delete;
};

template <typename T>
struct CompareSortOperation: SortOperation<T>
{
	T First;
	T Second;
	SortCompareType CompareType;
	bool CompareSuccess;
	CompareSortOperation(T _First, T _Second, SortCompareType _CompareType, bool _CompareSuccess): SortOperation(SortOperationType::Compare), First(_First), Second(_Second), CompareType(_CompareType), CompareSuccess(_CompareSuccess) { }
	
	FString CompareToString() const
	{
		FString Value = "";
		switch(CompareType)
		{
		case SortCompareType::None: Value = ""; break;
		case SortCompareType::LessThan: Value = "<"; break;
		case SortCompareType::MoreThan: Value = ">"; break;
		case SortCompareType::Equals: Value = "=="; break;
		case SortCompareType::NotEquals: Value = "!="; break;
		}
		return Value;
	}
};

template <typename T>
struct SwapSortOperation: SortOperation<T>
{
	T First;
	T Second;
	SwapSortOperation(T _First, T _Second): SortOperation(SortOperationType::Swap), First(_First), Second(_Second) { }
};