#pragma once
#include "SortAlgorithm.h"
class InsertionSort :
	public SortAlgorithm
{
public:
	InsertionSort();
	~InsertionSort();
	
	virtual void sort(std::vector<Bar> & bar) override;
	virtual void reset() override;
	virtual bool isSortFinished() override;
private:
	int j = 0;
};

