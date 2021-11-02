// Fill out your copyright notice in the Description page of Project Settings.


#include "SortRange.h"


// Sets default values
ASortRange::ASortRange()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SortActors = TArray<AActor*>();
	ItemDistance = 0;
	ItemSize = FVector(0, 0, 0);
}

void ASortRange::GenerateItems_Implementation(TSubclassOf<AActor> ItemClass, int Count)
{
}

void ASortRange::InitActor_Implementation(UPARAM(ref) AActor*& Actor, AActor*& InitializedActor)
{
	InitializedActor = Actor;
}

// Called when the game starts or when spawned
void ASortRange::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called when the game starts or when spawned
void ASortRange::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}


