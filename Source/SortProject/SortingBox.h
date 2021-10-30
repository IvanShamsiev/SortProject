// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Comparable.h"
#include "GameFramework/Actor.h"
#include "SortingBox.generated.h"

UCLASS()
class SORTPROJECT_API ASortingBox : public AActor, public IComparable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASortingBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	int BoxNumber;

	virtual void* GetCompareObject() override;
	virtual float Compare(IComparable& Other) override;

};
