#pragma once
#include "SortingBox.h"

struct ComparableWrapper: IComparable
{
	IComparable* Current;
	ComparableWrapper(): Current(nullptr) {}
	ComparableWrapper(IComparable* SBox): Current(SBox) {}

	virtual float Compare(IComparable& Other) override
	{
		return Current->Compare(*static_cast<ComparableWrapper&>(Other).Current);
	}
};
