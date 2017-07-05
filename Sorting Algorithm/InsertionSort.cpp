#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
	i = 1;
}


InsertionSort::~InsertionSort()
{
}
void InsertionSort::sort()
{
	for (size_t z = 0; z < speed_; z++)
	{
		if (i > barGraph->size() - 1) i = 1;

		if (j > 0 && barGraph->get(j - 1).getHeight() >= barGraph->get(j).getHeight())
		{
			std::swap(barGraph->get(j), barGraph->get(j - 1));
			sf::Vector2f temp = barGraph->get(j).getPos();
			barGraph->get(j).setPosition(barGraph->get(j - 1).getPos());

		
			barGraph->get(j - 1).setPosition(temp);

			j--;
		}
		else
		{
			float invlerp = (float)i / (float)barGraph->size();
			algoSound.setPitch(invlerp);
			algoSound.play();

			float value = (float)(i) / (float)barGraph->size();
			float lerp = (1 - value) + value * barGraph->size();
			sf::Color color(lerp * .5f, lerp * value, lerp * 10);
			barGraph->get(i).setColor(color);
			j = i;
			i++;
		}
	}
}

void InsertionSort::reset()
{
	i = 1;
}
