#include "ShapeProperty.h"
ShapeProperty::ShapeProperty(sf::Color fill, sf::Color outline, float thickness)
{
	fill_ = fill;
	outline_ = outline;
	thickness_ = thickness;

	colors.push_back(sf::Color::Red);
	colors.push_back(sf::Color(255, 165, 0));
	colors.push_back(sf::Color::Yellow);
	colors.push_back(sf::Color::Green);
	colors.push_back(sf::Color::Blue);
	colors.push_back(sf::Color(75, 0, 130));
	colors.push_back(sf::Color(127, 0, 255));
}
ShapeProperty::ShapeProperty()
{
}
ShapeProperty::~ShapeProperty()
{
}

int ShapeProperty::colorSize()
{
	return colors.size();
}

