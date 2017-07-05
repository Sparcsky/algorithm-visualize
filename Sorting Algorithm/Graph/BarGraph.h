#pragma once
#include <memory>
#include <unordered_map>
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

	Data data;

private:
	std::map<int,Bar> bars;
	std::map<int, Bar>::iterator it;
	std::unordered_map<int,sf::Vector2f> mapPos;
	ShapeProperty shapeProperty_;
	bool isShuffle= false;

};

