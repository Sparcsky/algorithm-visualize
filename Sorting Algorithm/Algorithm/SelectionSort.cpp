#include "SelectionSort.h"

SelectionSort::SelectionSort()
	:min(min)
{
}

SelectionSort::~SelectionSort()
{

}

void SelectionSort::sort(std::vector<Bar> & bar)
{

	for (size_t s = 0; s < speed_; s++)
	{
		if (isSortFinished()) return;

		min = &barGraph->get(i);

		for (size_t j = i; j < bar.size(); j++)
		{
			if (min->getHeight() > bar[j].getHeight())
			{
				min = &bar[j];

			}

		}
		float value = (float)(i) / (float)barGraph->size();
		float lerp = (1 - value) + value * barGraph->size();
		sf::Color color(lerp * .5f, lerp * value, lerp * 10);
		min->setColor(color);


		float invlerp = (float) i / (float) bar.size();
		algoSound.setPitch(invlerp);
		algoSound.play();

		utility::swap(*min,bar[i]);
		i++;

	}
}

bool SelectionSort::isSortFinished()
{
	if (i >= barGraph->size())
	{
		return true;
	}
	return false;
}

