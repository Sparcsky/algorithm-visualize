#include "MergeSort.h"
#include <iostream>
MergeSort::MergeSort()
{
}


MergeSort::~MergeSort()
{
}

void MergeSort::sort(std::vector<Bar> & bar)
{
	if (bar.size() <= 1) return;

	int mid = bar.size() / 2;

	std::vector<Bar> left;
	std::vector<Bar> right;

	left.reserve(mid);
	right.reserve(bar.size() - mid);

	for (size_t j = 0; j < mid;j++)
	{
		left.push_back(bar[j]);
	}
	for (size_t j = 0; j < bar.size() - mid; j++)
	{
		right.push_back(bar[mid + j]);
	}

	sort(left);
	sort(right);
	merge(left, right, bar);
}
void MergeSort::merge(std::vector<Bar> &left, std::vector<Bar> & right, std::vector<Bar>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, leftLoop = 0, rightLoop = 0;

	while (leftLoop < nL && rightLoop < nR)
	{
		if (left[leftLoop].getHeight() <= right[rightLoop].getHeight())
		{
			bars[i] = left[leftLoop++];
		}
		else
		{
			bars[i] = right[rightLoop++];
		}
		i++;
	}
	while (leftLoop < nL)
	{
		bars[i++] = left[leftLoop++];
	}
	while (rightLoop < nR)
	{
		bars[i++] = right[rightLoop++];
	}
}

bool MergeSort::isSortFinished()
{
	return false;
}
