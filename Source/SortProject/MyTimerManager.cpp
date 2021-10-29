#include "MyTimerManager.h"

MyTimerManager* MyTimerManager::Instance = nullptr;

MyTimerManager* MyTimerManager::GetInstance(TArray<ASortingBox*>& UArray,
		TArray<ASortingBox*>& SArray,
		FTimerManager* WTimerManager,
		TFunction<void()> OnFin)
{
	if (Instance == nullptr)
		Instance = new MyTimerManager(UArray, SArray, WTimerManager, OnFin);
	return Instance;
}

void MyTimerManager::Next()
{
	UE_LOG(LogTemp, Warning, TEXT("!MyTimerManager* = %d, size = %d"), this, size);
	UE_LOG(LogTemp, Warning, TEXT("!SortedArray* = %d, size = %d"), &SortedArray, SortedArray.Num());
	auto message = FString("Next(i = ").Append(FString::FromInt(i)).Append(")");
	GEngine->AddOnScreenDebugMessage(-1, 9999.0f, FColor::Red, message);
	if (i < size)
	{
		if (SortedArray.Num() > 1)
			SortedArray[i]->SetActorLocation(UnsortedArray[i]->GetActorLocation() + FVector(0, 300, 0));
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("SortedArray.Num() = %d"), SortedArray.Num());
			UE_LOG(LogTemp, Warning, TEXT("MyTimerManager* = %d"), this);
		}
		WorldTimerManager->SetTimer(h, [=](){ this->Next(); }, 5.0f, false);
		++i;
	} else OnFinish();
}
