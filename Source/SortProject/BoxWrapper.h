#pragma once
#include "SortingBox.h"

struct BoxWrapper: public IComparable
{
	ASortingBox* Box;
	BoxWrapper(): Box(nullptr) {}
	BoxWrapper(ASortingBox* SBox): Box(SBox) {}

	virtual float Compare(IComparable& Other) override
	{
		return Box->Compare(*static_cast<BoxWrapper&>(Other).Box);
	}
};
