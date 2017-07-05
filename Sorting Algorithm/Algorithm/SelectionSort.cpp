#include "SelectionSort.h"

SelectionSort::SelectionSort()
	:min(min)
{
}

SelectionSort::~SelectionSort()
{

}
#include <iostream>
void SelectionSort::sort()
{

	if (i >= barGraph->size())
	{
		i = 0;
	}
	min = &barGraph->get(i);

	for (size_t j = i; j < barGraph->size(); j++)
	{
		if (min->getHeight() > barGraph->get(j).getHeight())
		{
			min = &barGraph->get(j);
		}
	}
	utility::swap(*min, barGraph->get(i));
	i++;
}

