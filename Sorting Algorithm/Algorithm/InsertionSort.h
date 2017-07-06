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
	bool isFinish();
private:
	int j = 0;
	bool isFinished = false;
};

