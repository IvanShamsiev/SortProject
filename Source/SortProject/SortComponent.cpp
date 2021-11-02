// Fill out your copyright notice in the Description page of Project Settings.

#include "SortComponent.h"

#include "SortingBox.h"
#include "ComparableWrapper.h"
#include "SortingManagement/SortingManager.h"
#include "SortProject/ModifiedSortAlgorithm/BubbleSort.h"
#include "SortProject/ModifiedSortAlgorithm/BubbleSort.cpp"
#include "SortProject/ModifiedSortAlgorithm/QuickSort.h"
#include "SortProject/ModifiedSortAlgorithm/QuickSort.cpp"
#include "SortProject/ModifiedSortAlgorithm/InsertSort.h"
#include "SortProject/ModifiedSortAlgorithm/InsertSort.cpp"

USortComponent::USortComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USortComponent::StartSorting(UPARAM(ref) TArray<UObject*>& ComparableObjects, TArray<USortOperationBP*>& ResultsBP)
{
	UE_LOG(LogTemp, Warning, TEXT("--Check compiled 001--"));
	
	TArray<IComparable*> UnsortedArray;
	for (const auto Obj : ComparableObjects)
		if (Obj->Implements<UComparable>())
			UnsortedArray.Add(Cast<IComparable>(Obj));

	const size_t Size = UnsortedArray.Num();
	ComparableWrapper* Wrappers = new ComparableWrapper[Size];

	for (int i = 0; i < Size; ++i)
		Wrappers[i] = ComparableWrapper(UnsortedArray[i]);

	SortingManager<ComparableWrapper> SortManager(ESortAlgorithmType::InsertSort);
	SortManager.Sort(Wrappers, Size);

	ResultsBP = TArray<USortOperationBP*>();
	for (auto Result : SortManager.GetResults())
		ResultsBP.Add(USortOperationBP::GetFromNative(Result));

	//ShowSortingProcess(SortManager.GetResults(), Compare, Swap);
}

// Called when the game starts
void USortComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USortComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

