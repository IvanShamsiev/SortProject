#include "SortOperationBP.h"

USortOperationBP* USortOperationBP::GetFromNative(SortOperation<ComparableWrapper>* Native)
{
	if (Native->Type == SortOperationType::Compare)
	{
		const auto CompareNative = static_cast<CompareSortOperation<ComparableWrapper>*>(Native);
		ESortCompareTypeBP CompareType;
		switch (CompareNative->Compare)
		{
		case SortCompareType::LessThan: CompareType = ESortCompareTypeBP::LessThan; break;
		case SortCompareType::MoreThan: CompareType = ESortCompareTypeBP::MoreThan; break;
		case SortCompareType::Equals: CompareType = ESortCompareTypeBP::Equals; break;
		default: CompareType = ESortCompareTypeBP::None; break;
		}
		const auto Operation = NewObject<UCompareSortOperationBP>();
		Operation->First = Cast<UObject>(CompareNative->First.Current);
		Operation->Second = Cast<UObject>(CompareNative->Second.Current);
		Operation->Compare = CompareType;
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
	
	const auto Operation = NewObject<UCompareSortOperationBP>();
	Operation->Type = ESortOperationTypeBP::None;
	return Operation;
}