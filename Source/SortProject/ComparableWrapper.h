#pragma once
#include "SortingBox.h"

struct ComparableWrapper: IComparable
{
	IComparable* Current;
	ComparableWrapper(): Current(nullptr) {}
	ComparableWrapper(IComparable* Comparable): Current(Comparable) {}

	virtual float Compare(IComparable& Other) override
	{
		return Current->Compare(*static_cast<ComparableWrapper&>(Other).Current);
	}
	
	ComparableWrapper(const ComparableWrapper& Copy) : ComparableWrapper(Copy.Current) { }
 
	ComparableWrapper& operator= (const ComparableWrapper& Wrapper)
	{
		Current = Wrapper.Current;
		return *this;
	}
};
