#include "Utils.h"

void utility::swap(Bar & first, Bar & second)
{
	sf::Vector2f temp = first.getPos();
	first.setPosition(second.getPos());
	second.setPosition(temp);
	std::swap(first, second);
}

int utility::min(int a, int b)
{
	return a <= b ? a : b;
}
