#include "BubbleSort.h"
BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::sort()
{
	for (size_t z = 0; z < speed_; z++)
	{
		if (i >= dec && dec > 0)
		{
			float value = (float)(dec) / (float)barGraph->size();
			float lerp = (1 - value) + value * barGraph->size();

			sf::Color color(lerp * .5f, lerp * value, lerp * 10);
			barGraph->get(dec).setColor(color);
			dec--;
			i = 0;
		}
		
		if (barGraph->get(i).getHeight() > barGraph->get(i + 1).getHeight() && dec > 0)
		{
			utility::swap(barGraph->get(i), barGraph->get(i + 1));

			float invlerp = (float)i / (float)barGraph->size();
			algoSound.setPitch(invlerp);
			algoSound.play();
		}
		i++;
	}
}
