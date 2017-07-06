#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
	i = 1;
}

InsertionSort::~InsertionSort()
{
}
void InsertionSort::sort(std::vector<Bar> & bar)
{

	for (size_t z = 0; z < speed_; z++)
	{
		if (j > 0 && bar[j - 1].getHeight() >= bar[j].getHeight())
		{
			std::swap(bar[j], bar[j - 1]);
			sf::Vector2f temp = bar[j].getPos();

			bar[j].setPosition(bar[j - 1].getPos());
			bar[j - 1].setPosition(temp);
			j--;
		}
		else
		{
			if (!isSortFinished())
			{
				float invlerp = (float)i / (float)bar.size();
				algoSound.setPitch(invlerp);
				algoSound.play();
			}

			float value = (float)(i) / (float)bar.size();
			float lerp = (1 - value) + value *  bar.size();
			sf::Color color(lerp * .5f, lerp * value, lerp * 10);
			bar[i].setColor(color);
			j = i;
			i++;
		}
	}
}

void InsertionSort::reset()
{
	i = 1;
	isFinished = false;
}

bool InsertionSort::isSortFinished()
{
	if (i > barGraph->size() - 1)
	{
		i = 1;
		isFinished = true;
	}
	return isFinished;
}
