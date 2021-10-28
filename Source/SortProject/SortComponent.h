// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SortAIController.h"
#include "SortingBox.h"
#include "Components/ActorComponent.h"
#include "SortComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SORTPROJECT_API USortComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USortComponent();

	UFUNCTION(BlueprintCallable, Category="Default")
	void InitArray(UPARAM(ref) TArray<ASortingBox*>& a);

	UFUNCTION(BlueprintCallable, Category="Default")
	void StartSorting(ASortAIController* Controller, UPARAM(ref) TArray<ASortingBox*>& a);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	TArray<ASortingBox*> ArrayOfObjects;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
