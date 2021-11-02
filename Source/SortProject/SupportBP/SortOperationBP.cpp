#include "SortOperationBP.h"

USortOperationBP* USortOperationBP::GetFromNative(SortOperation<ComparableWrapper>* Native)
{
	if (Native->Type == SortOperationType::Compare)
	{
		const auto CompareNative = static_cast<CompareSortOperation<ComparableWrapper>*>(Native);
		ESortCompareTypeBP CompareType;
		switch (CompareNative->CompareType)
		{
		case SortCompareType::LessThan: CompareType = ESortCompareTypeBP::LessThan; break;
		case SortCompareType::MoreThan: CompareType = ESortCompareTypeBP::MoreThan; break;
		case SortCompareType::Equals: CompareType = ESortCompareTypeBP::Equals; break;
		default: CompareType = ESortCompareTypeBP::None; break;
		}
		const auto Operation = NewObject<UCompareSortOperationBP>();
		Operation->First = Cast<UObject>(CompareNative->First.Current);
		Operation->Second = Cast<UObject>(CompareNative->Second.Current);
		Operation->CompareType = CompareType;
		Operation->CompareSuccess = CompareNative->CompareSuccess;
		return Operation;
	}
	if (Native->Type == SortOperationType::Swap)
	{
		const auto SwapNative = static_cast<SwapSortOperation<ComparableWrapper>*>(Native);
		const auto Operation = NewObject<USwapSortOperationBP>();
		Operation->First = Cast<UObject>(SwapNative->First.Current);
		Operation->Second = Cast<UObject>(SwapNative->Second.Current);
		return Operation;
	}
	if (Native->Type == SortOperationType::CreateTemp)
	{
		const auto CreateTempNative = static_cast<CreateTempOperation<ComparableWrapper>*>(Native);
		const auto Operation = NewObject<UCreateTempOperation>();
		Operation->TempId = CreateTempNative->TempId;
		Operation->TempSize = CreateTempNative->TempSize;
		return Operation;
	}
	if (Native->Type == SortOperationType::RemoveTemp)
	{
		const auto RemoveTempNative = static_cast<RemoveTempOperation<ComparableWrapper>*>(Native);
		const auto Operation = NewObject<URemoveTempOperation>();
		Operation->TempId = RemoveTempNative->TempId;
		return Operation;
	}
	if (Native->Type == SortOperationType::CopyToTemp)
	{
		const auto CopyToTempNative = static_cast<CopyToTempOperation<ComparableWrapper>*>(Native);
		const auto Operation = NewObject<UCopyToTempOperation>();
		Operation->Item = Cast<UObject>(CopyToTempNative->Item.Current);
		Operation->TempId = CopyToTempNative->TempId;
		Operation->TempPosition = CopyToTempNative->TempPosition;
		return Operation;
	}
	if (Native->Type == SortOperationType::CopyFromTemp)
	{
		const auto CopyFromTempNative = static_cast<CopyFromTempOperation<ComparableWrapper>*>(Native);
		const auto Operation = NewObject<UCopyFromTempOperation>();
		Operation->Item = Cast<UObject>(CopyFromTempNative->Item.Current);
		Operation->TempId = CopyFromTempNative->TempId;
		Operation->ArrayPosition = CopyFromTempNative->ArrayPosition;
		return Operation;
	}
	
	const auto Operation = NewObject<UCompareSortOperationBP>();
	Operation->Type = ESortOperationTypeBP::None;
	return Operation;
}