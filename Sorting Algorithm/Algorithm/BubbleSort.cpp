#include "BubbleSort.h"
#include <iostream>
BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::sort(std::vector<Bar> & bar)
{
	if (isSortFinished()) return;

	for (size_t z = 0; z < speed_; z++)
	{
		if (i >= dec - 1)
		{
			float value = (float)(dec) / (float) bar.size();
			float lerp = (1 - value) + value *  bar.size();
			sf::Color color(lerp * .5f, lerp * value, lerp * 10);
			bar[i].setColor(color);
			dec--;
			i = 0;
		}

		if (bar[i].getHeight() >bar[i + 1].getHeight())
		{
			utility::swap(bar[i], bar[i + 1]);
			float invlerp = (float)i / (float)bar.size();
			algoSound.setPitch(invlerp);
			algoSound.play();
		}
		i++;
	}
}

bool BubbleSort::isSortFinished()
{
	if (dec < 0) return true;
	return false;
}
