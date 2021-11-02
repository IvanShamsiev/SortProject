#pragma once

#include "TempContainer.generated.h"

UCLASS(BlueprintType)
class UTempContainer: public UObject
{
	GENERATED_BODY()

	TMap<int, TArray<UObject*>> Temps;

	UFUNCTION(BlueprintCallable)
	void CreateTemp(const int Id, const int Size)
	{
		Temps[Id] = TArray<UObject*>();
	}
	
	UFUNCTION(BlueprintCallable)
	void RemoveTemp(const int Id)
	{
		Temps[Id].Empty();
	}

	UFUNCTION(BlueprintCallable)
	TArray<UObject*>& GetTempById(const int Id)
	{
		return Temps[Id];
	}
};
