#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
class ShapeProperty
{
public:
	ShapeProperty(sf::Color fill, sf::Color outline, float thickness);
	ShapeProperty();
	~ShapeProperty();

	sf::Color fill_;
	sf::Color outline_;
	float thickness_;
	std::vector<sf::Color> colors;
	int colorSize();
private:
	
};

