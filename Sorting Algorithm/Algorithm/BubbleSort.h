#pragma once
#include "SortAlgorithm.h"
class BubbleSort :
 public virtual SortAlgorithm
{
public:
	BubbleSort();
	~BubbleSort();

	virtual void sort() override;
	virtual bool isSortFinished()override;
protected:
};

