#pragma once
#include <memory>
#include "Bar.h"
#include "../Util/Utils.h"
class BarGraph
{
public:

	struct Data
	{
		float distance = 0;
		int barNumber = 0;
		sf::Vector2f size;
	};

	BarGraph(ShapeProperty shapeProperty);
	BarGraph();
	~BarGraph();

	Bar & get(int index);
	ShapeProperty & getShapeProperty();
	void shuffle();
	void update();
	void reset();
	void draw(sf::RenderWindow &window);
	bool isEmpty();
	int size();
	std::vector<Bar> &getItem();
	Data data;

private:
	std::vector<Bar> bars;
	ShapeProperty shapeProperty_;
	bool isShuffle= false;

};

