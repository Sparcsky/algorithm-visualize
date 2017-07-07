#pragma once
#include "SortAlgorithm.h"

class MergeSort :
	public SortAlgorithm
{
public:
	MergeSort();
	~MergeSort();

	virtual void sort(std::vector<Bar> & bar) override;
	void merge(std::vector<Bar> & left, std::vector<Bar> &right, std::vector<Bar> &bars);
	virtual bool isSortFinished() override;
private:
	void swap(std::vector<Bar>&left, std::vector<Bar> &right);
};

