#pragma once
#include "SortAlgorithm.h"
class InsertionSort :
	public SortAlgorithm
{
public:
	InsertionSort();
	~InsertionSort();
	
	virtual void sort();
	virtual void reset() override;

private:
	int j = 0;
};

