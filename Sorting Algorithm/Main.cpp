#pragma once
#include <SFML/Graphics.hpp>
#include "AlgorithmVisualise.h"


int main()
{
	unsigned int width = 1000;
	unsigned int height = 600;

	sf::RenderWindow window(sf::VideoMode(width, height), "Algorithm Visualizer");

	AlgorithmVisualise algorithmVisualise;
	algorithmVisualise.run(window);

	return EXIT_SUCCESS;
}