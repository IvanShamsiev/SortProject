// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComparableWrapper.h"
#include "EngineUtils.h"
#include "SortAIController.h"
#include "SortingBox.h"
#include "Components/ActorComponent.h"
#include "SortingManagement/SortOperation.h"
#include "SortComponent.generated.h"

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FCompareDelegate, UObject*, First, UObject*, Second, ESortCompareType, CompareType);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FSwapDelegate, UObject*, First, UObject*, Second);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SORTPROJECT_API USortComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USortComponent();

	UFUNCTION(BlueprintCallable, Category="Default")
	void StartSorting(UPARAM(ref) TArray<UObject*>& ComparableObjects, FCompareDelegate Compare, FSwapDelegate Swap);

	//UFUNCTION(BlueprintCallable, Category="Default")
	void ShowSortingProcess(TArray<SortOperation<ComparableWrapper>*>& Results, FCompareDelegate Compare, FSwapDelegate Swap);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	TArray<IComparable*> ArrayForSorting;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
