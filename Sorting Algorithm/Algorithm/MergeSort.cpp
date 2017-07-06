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
		left[j] = bars[j];
	}
	for (size_t j = 0; j < bars.size() - mid; j++)
	{
		right[j] = bars[mid + j];
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

//////////// void merge(vector<int>& left, vector<int>& right, vector<int>& nums)
////////////{
////////////	int nL = left.size();
////////////	int nR = right.size();
////////////	int i = 0, j = 0, k = 0;
////////////
////////////	while (j < nL && k < nR)
////////////	{
////////////		if (left[j] < right[k])
////////////		{
////////////			nums[i] = left[j];
////////////			j++;
////////////		}
////////////		else
////////////		{
////////////			nums[i] = right[k];
////////////			k++;
////////////		}
////////////		i++;
////////////	}
////////////	while (j < nL)
////////////	{
////////////		nums[i] = left[j];
////////////		i++;j++;
////////////	}
////////////	while (k < nR)
////////////	{
////////////		nums[i] = right[k];
////////////		i++;k++;
////////////	}
////////////
////////////}
