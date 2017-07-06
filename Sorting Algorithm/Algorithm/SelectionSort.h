#pragma once
#include "SortAlgorithm.h"
class SelectionSort :
	public SortAlgorithm
{
public:
	SelectionSort();
	~SelectionSort();
	virtual void sort() override;
	virtual bool isSortFinished() override;

private:
	int start = 0;
	Bar  * min;
};

