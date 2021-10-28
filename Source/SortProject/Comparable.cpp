// Fill out your copyright notice in the Description page of Project Settings.


#include "Comparable.h"

#include <memory>

#include "SortingBox.h"

// Add default functionality here for any IComparable functions that are not pure virtual.


bool IComparable::operator>(IComparable& Other)
{
	return Compare(Other) > 0;
}

bool IComparable::operator<(IComparable& Other)
{
	return Compare(Other) < 0;
}

bool IComparable::operator==(IComparable& Other)
{
	return Compare(Other) == 0;
}

bool IComparable::operator!=(IComparable& Other)
{
	return Compare(Other) != 0;
}