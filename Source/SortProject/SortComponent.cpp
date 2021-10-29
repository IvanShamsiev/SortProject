// Fill out your copyright notice in the Description page of Project Settings.


#include "SortComponent.h"

#include <string>

#include "SortingBox.h"
#include "BoxWrapper.h"
#include "ModifiedSortAlgoritm/SortAlgorithm.h"
#include "ModifiedSortAlgoritm/MergeSort.h"
#include "ModifiedSortAlgoritm/MergeSort.cpp"

// Sets default values for this component's properties
USortComponent::USortComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void USortComponent::InitArray(UPARAM(ref) TArray<ASortingBox*>& a)
{
	ArrayForSorting = a;
}

void USortComponent::StartSorting(ASortAIController* Controller, UPARAM(ref) TArray<ASortingBox*>& UnsortedArray)
{
	try
	{
		ArrayForSorting = UnsortedArray;
		size_t Size = UnsortedArray.Num();
		BoxWrapper* Boxes = new BoxWrapper[Size];
		for (int i = 0; i < Size; ++i)
			Boxes[i] = BoxWrapper(UnsortedArray[i]);
		
		GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, FString("-- Before Sort --"));
		for (int i = 0; i < Size; ++i)
		{
			auto message = FString("Array[")
				.Append(FString::FromInt(i)).Append("] = ")
				.Append(FString::FromInt(Boxes[i].Box->BoxNumber));
			GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, message);
		}
	
		SortAlgorithm<BoxWrapper>* alg = new MergeSort<BoxWrapper>();
		alg->Sort(Boxes, Size, [this](BoxWrapper* sorted, size_t size, TFunction<void()> Proceed)
		{
			TArray<ASortingBox*> array;
			for (int i = 0; i < size; ++i)
				array.Add(sorted[i].Box);
			UpdateSorting(this->ArrayForSorting, array, Proceed);
		});

		GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, FString("-- After Sort --"));
		for (int i = 0; i < Size; ++i)
		{
			auto message = FString("Array[")
				.Append(FString::FromInt(i)).Append("] = ")
				.Append(FString::FromInt(Boxes[i].Box->BoxNumber));
			GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, message);
		}
	}
	catch (std::exception e)
	{
		auto message = FString("Exception: ").Append(e.what());
		GEngine->AddOnScreenDebugMessage(-1, 99999.0f, FColor::Red, message);
	}
	
}

struct MyTimerManager
{
	TArray<ASortingBox*>& UnsortedArray;
	TArray<ASortingBox*>& SortedArray;
	FTimerHandle h;
	size_t size;
	size_t i;

	TFunction<void()> OnFinish;

	MyTimerManager(TArray<ASortingBox*>& UArray,
		TArray<ASortingBox*>& SArray,
		TFunction<void()> OnFin): UnsortedArray(UArray), SortedArray(SArray), OnFinish(OnFin)
	{
		size = UArray.Num();
		i = 0;
	}

	void Next()
	{
		if (i++ < size)
		{
			SortedArray[i]->SetActorLocation(UnsortedArray[i]->GetActorLocation());
			FTimerManager::SetTimer(h, [this](){ Next(); }, 5.0f, false);
		}
	}
};

void USortComponent::UpdateSorting(UPARAM(ref) TArray<ASortingBox*>& UnsortedArray,
	UPARAM(ref) TArray<ASortingBox*>& SortedArray,
	TFunction<void()> OnFinish)
{
	MyTimerManager MyManager(UnsortedArray, SortedArray, OnFinish);
	MyManager.Next();
}


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

