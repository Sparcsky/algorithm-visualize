#include "Bar.h"

Bar::Bar()
{
	
}

Bar::~Bar()
{
}

void Bar::setProperty(ShapeProperty & shapeProperty)
{
	shapeProperty_ = shapeProperty;
	rect.setFillColor(shapeProperty.fill_);
	rect.setOutlineColor(shapeProperty.outline_);
	rect.setOutlineThickness(shapeProperty.thickness_);
}

void Bar::setPosition(sf::Vector2f pos)
{
	rect.setPosition(pos);
}

void Bar::setSize(sf::Vector2f size)
{
	rect.setOrigin(rect.getOrigin().x, size.y);
	rect.setSize(size);
}

void Bar::draw(sf::RenderWindow & window)
{
	window.draw(rect);
}


void Bar::setColor(sf::Color color)
{
	rect.setFillColor(color);
}

void Bar::changeColor(int i)
{
	rect.setFillColor(shapeProperty_.colors[i]);
}

int Bar::getWidth()
{
	return rect.getGlobalBounds().width;
}

int Bar::getHeight()
{
	return rect.getGlobalBounds().height;
}

sf::Vector2f Bar::getPos()
{
	return rect.getPosition();
}

ShapeProperty Bar::getShapeProperty()
{
	return shapeProperty_;
}
