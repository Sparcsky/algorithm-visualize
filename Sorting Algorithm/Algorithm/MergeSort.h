#pragma once
#include "SortAlgorithm.h"

class MergeSort :
	public SortAlgorithm
{
public:
	MergeSort();
	~MergeSort();

	virtual void sort() override;
	void mergeSort(std::vector<Bar> &bars);
	void merge(std::vector<Bar> &left, std::vector<Bar> &right, std::vector<Bar> &bars);
private:
	void swap(std::vector<Bar>&left, std::vector<Bar> &right);
};

