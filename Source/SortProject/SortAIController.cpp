// Fill out your copyright notice in the Description page of Project Settings.


#include "SortAIController.h"

ASortAIController::ASortAIController()
{
	//auto message = FString("My name is: ").Append(GetName());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, message);
}


void ASortAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//MoveToLocation(FVector(0, 0, 0));

	//FAIMoveRequest r(FVector(0, 0, 0));
	//MoveTo(r);
	
	//auto message = FString("Tick");
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, message);
}

void ASortAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	auto message = FString("Pawn: ").Append(InPawn->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, message);
}
