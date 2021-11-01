// Fill out your copyright notice in the Description page of Project Settings.


#include "SortComponent.h"

#include <memory>
#include <string>

#include "SortingBox.h"
#include "ComparableWrapper.h"
#include "SortingManagement/SortingManager.h"
#include "SortProject/ModifiedSortAlgorithm/BubbleSort.h"
#include "SortProject/ModifiedSortAlgorithm/BubbleSort.cpp"
#include "SortProject/ModifiedSortAlgorithm/QuickSort.h"
#include "SortProject/ModifiedSortAlgorithm/QuickSort.cpp"

// Sets default values for this component's properties
USortComponent::USortComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
	//auto message = FString("OK!");
	//GEngine->AddOnScreenDebugMessage(1, 999.f, FColor::Red, message);
}

void USortComponent::StartSorting(UPARAM(ref) TArray<UObject*>& ComparableObjects, TArray<USortOperationBP*>& ResultsBP)
{
	UE_LOG(LogTemp, Warning, TEXT("--Check compiled 001--"));
	
	TArray<IComparable*> UnsortedArray;
	for (const auto Obj : ComparableObjects)
		if (Obj->Implements<UComparable>())
			UnsortedArray.Add(Cast<IComparable>(Obj));
	
	size_t Size = UnsortedArray.Num();
	ComparableWrapper* Wrappers = new ComparableWrapper[Size];

	for (int i = 0; i < Size; ++i)
		Wrappers[i] = ComparableWrapper(UnsortedArray[i]);
	
	UE_LOG(LogTemp, Warning, TEXT("--Before sort--"));
	for (int i = 0; i < Size; ++i)
		UE_LOG(LogTemp, Warning, TEXT("Array[%d] = %d"), i, *static_cast<int*>(Wrappers[i].Current->GetCompareObject()));

	SortingManager<ComparableWrapper> SortManager(ESortAlgorithmType::QuickSort);
	SortManager.Sort(Wrappers, Size);

	UE_LOG(LogTemp, Warning, TEXT("--After sort--"));
	for (int i = 0; i < Size; ++i)
		UE_LOG(LogTemp, Warning, TEXT("Array[%d] = %d"), i, *static_cast<int*>(Wrappers[i].Current->GetCompareObject()));
	UE_LOG(LogTemp, Warning, TEXT(""));

	ResultsBP = TArray<USortOperationBP*>();
	for (auto Result : SortManager.GetResults())
		ResultsBP.Add(USortOperationBP::GetFromNative(Result));

	//ShowSortingProcess(SortManager.GetResults(), Compare, Swap);
}

/*void USortComponent::ShowSortingProcess(TArray<SortOperation<ComparableWrapper>*>& Results, FCompareDelegate Compare, FSwapDelegate Swap)
{
	for (auto Result : Results)
	{
		SwapSortOperation<ComparableWrapper>* SwapResult = nullptr;
		CompareSortOperation<ComparableWrapper>* CompareResult = nullptr;
		switch (Result->Type)
		{
		case SortOperationType::Swap:
			SwapResult = static_cast<SwapSortOperation<ComparableWrapper>*>(Result);
			UE_LOG(LogTemp, Warning, TEXT("Swap(%d, %d)"), *static_cast<int*>(SwapResult->First.Current->GetCompareObject()), *static_cast<int*>(SwapResult->Second.Current->GetCompareObject()));
			Swap.ExecuteIfBound(Cast<UObject>(SwapResult->First.Current), Cast<UObject>(SwapResult->Second.Current));
			break;
		case SortOperationType::Compare:
			CompareResult = static_cast<CompareSortOperation<ComparableWrapper>*>(Result);
			
			UE_LOG(LogTemp, Warning, TEXT("Compare: %d %s %d ?"), *static_cast<int*>(CompareResult->First.Current->GetCompareObject()), *CompareResult->CompareToString(), *static_cast<int*>(CompareResult->Second.Current->GetCompareObject()));
			Compare.ExecuteIfBound(Cast<UObject>(CompareResult->First.Current), Cast<UObject>(CompareResult->Second.Current), CompareResult->Compare);
			break;
		case SortOperationType::None:
			UE_LOG(LogTemp, Warning, TEXT("UNEXPECTED BEHAVIOR: Result.Type = None"));
			break;
		}
	}
}*/

// Called when the game starts
void USortComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USortComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

