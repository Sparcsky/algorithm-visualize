#pragma once
#include <SFML\Graphics.hpp>
#include "ShapeProperty.h"
class Bar
{

public:

	Bar();
	~Bar();

	void setProperty(ShapeProperty & property);
	void setPosition(sf::Vector2f pos);
	void setSize(sf::Vector2f size);
	void draw(sf::RenderWindow &window);
	void setColor(sf::Color color);
	void changeColor(int i);
	int getWidth();
	int getHeight();
	sf::Vector2f getPos();
	ShapeProperty getShapeProperty();

private:
	sf::RectangleShape rect;
	ShapeProperty shapeProperty_;
};

