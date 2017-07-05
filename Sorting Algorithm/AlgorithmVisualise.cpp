#include "AlgorithmVisualise.h"
#include <iostream>
AlgorithmVisualise::AlgorithmVisualise()
	:barProperty(sf::Color::Black, sf::Color::Red, 0)
{
	if (buffer.loadFromFile("Assets/Do.wav"));
	barGraph = BarGraph(barProperty);

	gui.sliders[0].setValue(200);
	gui.sliders[1].setValue(2000);
}
AlgorithmVisualise::~AlgorithmVisualise()
{
}
void AlgorithmVisualise::run(sf::RenderWindow &window)
{
	sf::Event event;
	sf::Mouse mouse;
	sf::Vector2f mousePos;

	while (window.isOpen())
	{
		mousePos = window.mapPixelToCoords(sf::Vector2i(mouse.getPosition(window)));

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			handleInput(event, mousePos);

		}
		selectSort = gui.itemList.selectItem(mousePos);

		window.clear(sf::Color::White);
		if (start)
		{
			sortAlgorithm->setSpeed(gui.sliders[0].getValue());
			sortAlgorithm->sort();
		}
		if (gui.textButtons[2].checked && !start)
		{
			gui.act(event, mousePos);
			barGraph.data.barNumber = gui.sliders[1].getValue();
			barGraph.data.size.x = gui.sliders[2].getValue();
			barGraph.data.size.y = gui.sliders[3].getValue();
			barGraph.data.distance = gui.sliders[4].getValue();
			barGraph.update();
		}

		barGraph.draw(window);
		gui.display(window);
		window.display();
	}
}

void AlgorithmVisualise::handleInput(sf::Event & event, sf::Vector2f mousePos)
{

	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	case sf::Event::MouseButtonPressed:
		if (gui.textButtons[0].isChecked(event, mousePos) && !start)
		{
			sortAlgorithm = AlgorithmFactory::getAlgorithm(selectSort);
			sortAlgorithm->setVisual(barGraph);
			sortAlgorithm->setSound(buffer);
			barGraph.shuffle();
		}
		else if (gui.textButtons[1].isChecked(event, mousePos))
		{
			barGraph.reset();
			std::cout << "1" << std::endl;
		}
		else if (gui.textButtons[2].isChecked(event, mousePos))
		{
			std::cout << "2" << std::endl;

		}
		else if (gui.textButtons[3].isChecked(event, mousePos))
		{
			std::cout << "3" << std::endl;

		}
		start = gui.textButtons[0].checked;
	}
}
