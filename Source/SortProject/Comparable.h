// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Comparable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UComparable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SORTPROJECT_API IComparable
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual float Compare(IComparable& Other) = 0;
	virtual bool operator > (IComparable& Other);
	virtual bool operator < (IComparable& Other);
	virtual bool operator == (IComparable& Other);
	virtual bool operator != (IComparable& Other);
};
