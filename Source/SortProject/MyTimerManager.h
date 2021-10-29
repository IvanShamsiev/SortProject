#pragma once
#include "SortingBox.h"

struct MyTimerManager
{
	
	TArray<ASortingBox*> UnsortedArray;
	TArray<ASortingBox*> SortedArray;
	FTimerManager* WorldTimerManager;
	FTimerHandle h;
	size_t size;
	size_t i;

	TFunction<void()> OnFinish;

	static MyTimerManager* GetInstance(TArray<ASortingBox*>& UArray,
		TArray<ASortingBox*>& SArray,
		FTimerManager* WTimerManager,
		TFunction<void()> OnFin);
	
	void Next();

protected:
	static MyTimerManager* Instance;
	
	MyTimerManager(TArray<ASortingBox*>& UArray,
		TArray<ASortingBox*>& SArray,
		FTimerManager* WTimerManager,
		TFunction<void()> OnFin):	UnsortedArray(TArray<ASortingBox*>(UArray)),
									SortedArray(TArray<ASortingBox*>(SArray)),
									WorldTimerManager(WTimerManager), 
									size(UnsortedArray.Num()), i(0), OnFinish(OnFin) { }

public:
	
	MyTimerManager(MyTimerManager &other) = delete;
	
	void operator=(const MyTimerManager&) = delete;
};
