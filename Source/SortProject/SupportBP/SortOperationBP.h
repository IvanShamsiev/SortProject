#pragma once
#include "SortProject/ComparableWrapper.h"
#include "SortProject/SortingManagement/SortOperation.h"
#include "SortOperationBP.generated.h"

UENUM(BlueprintType)
enum class ESortOperationTypeBP : uint8
{
	None UMETA(DisplayName = "None"),
	Compare UMETA(DisplayName = "Compare"),
	Swap UMETA(DisplayName = "Swap")
};

UENUM(BlueprintType)
enum class ESortCompareTypeBP : uint8
{
	None UMETA(DisplayName = "None"),
	MoreThan UMETA(DisplayName = "MoreThan"),
	LessThan UMETA(DisplayName = "LessThan"),
	Equals UMETA(DisplayName = "Equals"),
	NotEquals UMETA(DisplayName = "NotEquals")
};

UCLASS(BlueprintType)
class USortOperationBP: public UObject
{
public:
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ESortOperationTypeBP Type;
	
	USortOperationBP(): Type(ESortOperationTypeBP::None) { }
	USortOperationBP(ESortOperationTypeBP _Type): Type(_Type) { }

	static USortOperationBP* GetFromNative(SortOperation<ComparableWrapper>* Native);
};

UCLASS(BlueprintType)
class UCompareSortOperationBP: public USortOperationBP
{
public:
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* First;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* Second;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ESortCompareTypeBP CompareType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool CompareSuccess;
	
	UCompareSortOperationBP(): USortOperationBP(ESortOperationTypeBP::Compare), First(nullptr), Second(nullptr), CompareType(ESortCompareTypeBP::None), CompareSuccess(false) { }
	UCompareSortOperationBP(UObject* _First, UObject* _Second, ESortCompareTypeBP _CompareType, bool _CompareSuccess): USortOperationBP(ESortOperationTypeBP::Compare), First(_First), Second(_Second), CompareType(_CompareType), CompareSuccess(_CompareSuccess) { }
	
	FString CompareToString() const
	{
		FString Value = "";
		switch(CompareType)
		{
		case ESortCompareTypeBP::None: Value = ""; break;
		case ESortCompareTypeBP::LessThan: Value = "<"; break;
		case ESortCompareTypeBP::MoreThan: Value = ">"; break;
		case ESortCompareTypeBP::Equals: Value = "=="; break;
		case ESortCompareTypeBP::NotEquals: Value = "!="; break;
		}
		return Value;
	}
};

UCLASS(BlueprintType)
class USwapSortOperationBP: public USortOperationBP
{
public:
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* First;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* Second;
	
	USwapSortOperationBP(): USortOperationBP(ESortOperationTypeBP::Swap), First(nullptr), Second(nullptr) { }
	USwapSortOperationBP(UObject* _First, UObject* _Second): USortOperationBP(ESortOperationTypeBP::Swap), First(_First), Second(_Second) { }
};