#pragma once
#include "SortAlgorithm.h"

class MergeSort :
	public SortAlgorithm
{
public:
	MergeSort();
	~MergeSort();

	virtual void sort() override;
};

