#pragma once
#include "SortAlgorithm.h"

class MergeSort :
	public SortAlgorithm
{
public:
	MergeSort();
	~MergeSort();

	virtual void sort() override;
	void mergeSort(std::map<int, Bar> &bars);
	void merge(std::map<int, Bar> &left, std::map<int, Bar> &right, std::map<int, Bar> &bars);
private:
	void swap(std::map<int, Bar> &left, std::map<int, Bar> &right);
};

