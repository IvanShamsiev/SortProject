// Fill out your copyright notice in the Description page of Project Settings.


#include "SortingBot.h"

#include "SortAIController.h"
#include "Chaos/Utilities.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"

// Sets default values
ASortingBot::ASortingBot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//AIControllerClass = TSubclassOf<ASortAIController>();
	//Controller = CreateDefaultSubobject<ASortAIController>("My controller");

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

// Called when the game starts or when spawned
void ASortingBot::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASortingBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//auto message = FString("Controller: ").Append(GetController()->GetName());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, message);
	//printf("Controller: %ls", ToCStr(Controller->GetName()));
}

// Called to bind functionality to input
void ASortingBot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

