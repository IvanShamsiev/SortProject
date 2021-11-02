// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SortRange.generated.h"

UCLASS()
class SORTPROJECT_API ASortRange : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASortRange();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AActor*> SortActors;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float ItemDistance;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FVector ItemSize;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void GenerateItems(TSubclassOf<AActor> ItemClass, int Count);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InitActor(UPARAM(ref) AActor*& Actor, AActor*& InitializedActor);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
