#include "BubbleSort.h"
#include <iostream>
BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::sort()
{
	if (dec < 0) return;

	for (size_t z = 0; z < speed_; z++)
	{
		if (i >= dec - 1)
		{
			float value = (float)(dec) / (float)barGraph->size();
			float lerp = (1 - value) + value * barGraph->size();
			sf::Color color(lerp * .5f, lerp * value, lerp * 10);
			barGraph->get(i).setColor(color);
			dec--;
			i = 0;
		}

		if (barGraph->get(i).getHeight() > barGraph->get(i + 1).getHeight())
		{
			utility::swap(barGraph->get(i), barGraph->get(i + 1));
			float invlerp = (float)i / (float)barGraph->size();
			algoSound.setPitch(invlerp);
			algoSound.play();
		}
		i++;
	}
}
