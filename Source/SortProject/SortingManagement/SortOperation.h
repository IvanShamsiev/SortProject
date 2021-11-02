#pragma once

enum class SortOperationType
{
	None,
	Compare,
	Swap,
	CreateTemp,
	RemoveTemp,
	CopyToTemp,
	CopyFromTemp
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

template <typename T>
struct CreateTempOperation: SortOperation<T>
{
	unsigned int TempId;
	size_t TempSize;
	CreateTempOperation(unsigned int _TempId, size_t _TempSize): SortOperation(SortOperationType::CreateTemp), TempId(_TempId), TempSize(_TempSize) { }
};

template <typename T>
struct RemoveTempOperation: SortOperation<T>
{
	unsigned int TempId;
	RemoveTempOperation(unsigned int _TempId): SortOperation(SortOperationType::RemoveTemp), TempId(_TempId) { }
};

template <typename T>
struct CopyToTempOperation: SortOperation<T>
{
	T Item;
	unsigned int TempId;
	size_t TempPosition;
	CopyToTempOperation(T _Item, unsigned int _TempId, size_t _TempPosition): SortOperation(SortOperationType::CopyToTemp), Item(_Item), TempId(_TempId), TempPosition(_TempPosition) { }
};

template <typename T>
struct CopyFromTempOperation: SortOperation<T>
{
	T Item;
	unsigned int TempId;
	size_t ArrayPosition;
	CopyFromTempOperation(T _Item, unsigned int _TempId, size_t _ArrayPosition): SortOperation(SortOperationType::CopyFromTemp), Item(_Item), TempId(_TempId), ArrayPosition(_ArrayPosition) { }
};