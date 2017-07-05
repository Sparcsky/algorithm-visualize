#pragma once
#include <SFML/Audio.hpp>
#include "../Algorithm/AlgorithmFactory.h"
#include "../Algorithm/BubbleSort.h"
#include "../Graph/BarGraph.h"
#include "../Hud/Gui.h"

class AlgorithmVisualise
{
public:
	AlgorithmVisualise();
	~AlgorithmVisualise();

	void handleInput(sf::Event & event, sf::Vector2f mousePos);
	void updateData();
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

