#pragma once
#include <string>
#include <memory>
#include "SortAlgorithm.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"

class AlgorithmFactory
{
public:
	AlgorithmFactory();
	~AlgorithmFactory();

	static std::shared_ptr<SortAlgorithm> getAlgorithm(std::string name);
};

