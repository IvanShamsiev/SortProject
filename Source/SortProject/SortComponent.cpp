// Fill out your copyright notice in the Description page of Project Settings.


#include "SortComponent.h"

#include <string>

#include "SortingBox.h"
#include "BoxWrapper.h"
#include "ModifiedSortAlgorithm/SortAlgorithm.h"
#include "ModifiedSortAlgorithm/BubbleSort.h"
#include "ModifiedSortAlgorithm/BubbleSort.cpp"

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

		SortingManager<BoxWrapper> Manager(nullptr);
		SortAlgorithm<BoxWrapper>* alg = new BubbleSort<BoxWrapper>(&Manager);
		Manager.Algorithm = alg;
		alg->Sort(Boxes, Size);

		GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, FString("-- After Sort --"));
		for (int i = 0; i < Size; ++i)
		{
			auto message = FString("Array[")
				.Append(FString::FromInt(i)).Append("] = ")
				.Append(FString::FromInt(Boxes[i].Box->BoxNumber));
			GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, message);
		}

		ShowSortingProcess(Manager.GetResults());
	}
	catch (std::exception e)
	{
		auto message = FString("Exception: ").Append(e.what());
		GEngine->AddOnScreenDebugMessage(-1, 99999.0f, FColor::Red, message);
	}
}

void USortComponent::ShowSortingProcess(TArray<SortOperation<BoxWrapper>*>& Results)
{
	for (int i = 0; i < Results.Num(); ++i)
	{
		auto Result = Results[i];
		//UE_LOG(LogTemp, Warning, TEXT("Result* = %d; type = %d"), Result, Result->Type);
		SwapSortOperation<BoxWrapper>* SwapResult = nullptr;
		CompareSortOperation<BoxWrapper>* CompareResult = nullptr;
		switch (Result->Type)
		{
		case ESortOperationType::Swap:
			SwapResult = static_cast<SwapSortOperation<BoxWrapper>*>(Result);
			UE_LOG(LogTemp, Warning, TEXT("Swap(%d, %d)"), SwapResult->First.Box->BoxNumber, SwapResult->Second.Box->BoxNumber);
			break;
		case ESortOperationType::Compare:
			CompareResult = static_cast<CompareSortOperation<BoxWrapper>*>(Result);
			UE_LOG(LogTemp, Warning, TEXT("Compare: %d %s %d ?"), CompareResult->First.Box->BoxNumber, *CompareResult->CompareToString(), CompareResult->Second.Box->BoxNumber);
			break;
		case ESortOperationType::None:
			UE_LOG(LogTemp, Warning, TEXT("UNEXPECTED BEHAVIOR: Result.Type = None"));
			break;
		}
	}
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

