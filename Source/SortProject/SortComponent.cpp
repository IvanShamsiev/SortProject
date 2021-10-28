// Fill out your copyright notice in the Description page of Project Settings.


#include "SortComponent.h"

#include <string>

#include "SortingBox.h"
#include "Concepts/EqualityComparable.h"
#include "SortAlgoritm/SortAlgorithm.h"
#include "SortAlgoritm/MergeSort.h"
#include "SortAlgoritm/MergeSort.cpp"

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
	ArrayOfObjects = a;
}

struct BoxStruct
{
	ASortingBox* SortingBox;

	BoxStruct()
	{
		SortingBox = nullptr;
	}

	BoxStruct(ASortingBox* Box)
	{
		SortingBox = Box;
	}
		
	bool operator != (BoxStruct& Box) const
	{
		return SortingBox->BoxNumber != Box.SortingBox->BoxNumber;
	}
	bool operator == (BoxStruct& Box) const
	{
		return SortingBox->BoxNumber == Box.SortingBox->BoxNumber;
	}
	bool operator < (BoxStruct& Box) const
	{
		return SortingBox->BoxNumber < Box.SortingBox->BoxNumber;
	}
	bool operator > (BoxStruct& Box) const
	{
		return SortingBox->BoxNumber > Box.SortingBox->BoxNumber;
	}
};

void USortComponent::StartSorting(ASortAIController* Controller, UPARAM(ref) TArray<ASortingBox*>& a)
{
	try
	{
		size_t Size = a.Num();
		BoxStruct* Boxes = new BoxStruct[Size];
		for (int i = 0; i < Size; ++i)
			Boxes[i] = BoxStruct(a[i]);
		CEqualityComparable
		
		GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, FString("-- Before Sort --"));
		for (int i = 0; i < Size; ++i)
		{
			auto message = FString("Array[")
				.Append(FString::FromInt(i)).Append("] = ")
				.Append(FString::FromInt(Boxes[i].SortingBox->BoxNumber));
			GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, message);
		}
	
		SortAlgorithm<BoxStruct>* alg = new MergeSort<BoxStruct>();
		alg->Sort(Boxes, Size);

		GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, FString("-- After Sort --"));
		for (int i = 0; i < Size; ++i)
		{
			auto message = FString("Array[")
				.Append(FString::FromInt(i)).Append("] = ")
				.Append(FString::FromInt(Boxes[i].SortingBox->BoxNumber));
			GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, message);
		}
	}
	catch (std::exception e)
	{
		auto message = FString("Exception: ").Append(e.what());
		GEngine->AddOnScreenDebugMessage(-1, 99999.0f, FColor::Red, message);
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

