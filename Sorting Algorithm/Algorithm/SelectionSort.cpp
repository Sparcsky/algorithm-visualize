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
		return;
	}
	min = &barGraph->get(i);

	for (size_t j = i; j < barGraph->size(); j++)
	{
		if (min->getHeight() > barGraph->get(j).getHeight())
		{
			min = &barGraph->get(j);
		
		}
		
	}
	float value = (float)(i) / (float)barGraph->size();
	float lerp = (1 - value) + value * barGraph->size();
	sf::Color color(lerp * .5f, lerp * value, lerp * 10);
	min->setColor(color);


	float invlerp = (float) i / (float)barGraph->size();
	algoSound.setPitch(invlerp);
	algoSound.play();

	utility::swap(*min, barGraph->get(i));
	i++;
}

bool SelectionSort::isSortFinished()
{
	return false;
}

