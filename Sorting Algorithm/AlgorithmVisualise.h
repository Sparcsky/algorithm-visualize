#pragma once
#include <SFML\Audio.hpp>
#include "AlgorithmFactory.h"
#include "BubbleSort.h"
#include "BarGraph.h"
#include "Gui.h"

class AlgorithmVisualise
{
public:
	AlgorithmVisualise();
	~AlgorithmVisualise();

	void handleInput(sf::Event & event, sf::Vector2f mousePos);
	void run(sf::RenderWindow &window);

private:
	Gui gui;
	std::shared_ptr<SortAlgorithm> sortAlgorithm;
	ShapeProperty barProperty;

	BarGraph barGraph;
	std::string selectSort;
	sf::SoundBuffer buffer;
	sf::Sound algoSound;
	bool start = false;

};

