#include "Utils.h"

void utility::swap(Bar & first, Bar & second)
{
	std::swap(first, second);
	sf::Vector2f temp = first.getPos();
	first.setPosition(second.getPos());
	second.setPosition(temp);
}
