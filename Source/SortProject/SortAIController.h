// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SortAIController.generated.h"

/**
 * 
 */
UCLASS()
class SORTPROJECT_API ASortAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASortAIController();

	virtual void Tick(float DeltaSeconds) override;

	virtual void OnPossess(APawn* InPawn) override;
};
