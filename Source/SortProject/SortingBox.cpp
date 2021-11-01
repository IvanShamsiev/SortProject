// Fill out your copyright notice in the Description page of Project Settings.


#include "SortingBox.h"

// Sets default values
ASortingBox::ASortingBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASortingBox::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASortingBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void* ASortingBox::GetCompareObject()
{
	return &BoxNumber;
}

float ASortingBox::Compare(IComparable& Other)
{
	return BoxNumber - static_cast<ASortingBox*>(&Other)->BoxNumber;
}

