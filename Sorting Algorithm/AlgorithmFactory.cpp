#include "AlgorithmFactory.h"
#include <iostream>

AlgorithmFactory::AlgorithmFactory()
{
}

AlgorithmFactory::~AlgorithmFactory()
{
}

std::shared_ptr<SortAlgorithm> AlgorithmFactory::getAlgorithm(std::string name)
{
	std::shared_ptr<SortAlgorithm> sort;

	if (name == "Bubble sort")
	{
		sort.reset(new BubbleSort());
	}
	else if (name == "Insertion sort")
	{
		sort.reset(new InsertionSort());
	}
	return sort;
}

