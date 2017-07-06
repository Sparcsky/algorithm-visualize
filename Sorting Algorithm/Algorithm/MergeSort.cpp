#include "MergeSort.h"

MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}
#include <iostream>

void MergeSort::sort()
{
	mergeSort(barGraph->getItem());
}

void MergeSort::mergeSort(std::vector<Bar> & bars)
{

	if (bars.size() <= 1) return;

	std::vector<Bar> left;
	std::vector<Bar>right;

	int mid = bars.size() / 2;
	for (size_t j = 0; j < mid;j++)
	{
		left.push_back(bars[j]);
	}
	for (size_t j = 0; j < bars.size() - mid; j++)
	{
		right.push_back(bars[mid + j]);
	}
	mergeSort(left);
	mergeSort(right);
	merge(left, right, bars);
}

void MergeSort::merge(std::vector<Bar>& left, std::vector<Bar>& right, std::vector<Bar>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j].getHeight() < right[k].getHeight())
		{
			utility::swap(left[j], bars[i]);
			j++;
		}
		else
		{
			utility::swap(right[k], bars[i]);
			k++;
		}
		i++;
	}
	while (j < nL)
	{
		utility::swap(left[j], bars[i]);
		j++;
		i++;
	}
	while (k < nR)
	{
		utility::swap(right[k], bars[i]);
		k++;
		i++;
	}
}

bool MergeSort::isSortFinished()
{
	return false;
}
