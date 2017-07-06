#include "BarGraph.h"
BarGraph::BarGraph(ShapeProperty shapeProperty)
	:shapeProperty_(shapeProperty)
{

}
BarGraph::BarGraph()
{
}

BarGraph::~BarGraph()
{
}

Bar & BarGraph::get(int index)
{
	return bars[index];
}

ShapeProperty & BarGraph::getShapeProperty()
{
	return shapeProperty_;
}

void BarGraph::shuffle()
{
	srand(time(NULL));

	for (size_t i = 0; i < size(); i++)
	{
		int x = rand() % bars.size();
		utility::swap(bars[i], bars[x]);
	}
}

void BarGraph::update()
{
	if (bars.size() > data.barNumber)
	{
		bars.resize(data.barNumber);
	}
	else
	{
		for (size_t i = 0; i < data.barNumber; i++)
		{
			if (bars.size() < data.barNumber)
			{
				Bar bar;
				bar.setProperty(shapeProperty_);
				bars.push_back(bar);
			}

			sf::Vector2f size_(data.size.x, i * data.size.y);
			sf::Vector2f pos_(i * data.distance, 600);
			bars[i].setPosition(pos_);
			bars[i].setSize(size_);
		}
	}
}

void BarGraph::reset()
{
	for (size_t i = 0; i < size(); i++)
	{
		sf::Vector2f size_(data.size.x, i * data.size.y);
		sf::Vector2f pos_(i * data.distance, 600);
		bars[i].setPosition(pos_);
		bars[i].setSize(size_);
		bars[i].setColor(sf::Color::Black);
	}
}

bool BarGraph::isEmpty()
{
	return bars.empty();
}

void BarGraph::draw(sf::RenderWindow & window)
{
	if (bars.empty()) return;

	for (size_t i = 0; i < bars.size(); i++)
	{
		bars[i].draw(window);
	}
}

int BarGraph::size()
{
	return bars.size();
}

std::vector<Bar> & BarGraph::getItem()
{
	return bars;
}
