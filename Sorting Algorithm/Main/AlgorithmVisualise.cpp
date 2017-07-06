#include "AlgorithmVisualise.h"
#include <iostream>

AlgorithmVisualise::AlgorithmVisualise()
	:barProperty(sf::Color::Black, sf::Color::Red, 0)
{
	if (buffer.loadFromFile("Assets/Do.wav"));
	barGraph = BarGraph(barProperty);

	gui.sliders[0].setValue(500);
	gui.sliders[1].setValue(2000);
	gui.textButtons[0].disable = true;
	gui.textButtons[2].disable = true;
	gui.textButtons[3].disable = true;

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

		if (start)
		{
			sortAlgorithm->setSpeed(gui.sliders[0].getValue());
			sortAlgorithm->sort();
		}
		else if (gui.textButtons[1].checked)
		{
			gui.updateSlider(mousePos);
			updateData();
			barGraph.update();
		}


		window.clear(sf::Color::White);
		barGraph.draw(window);
		gui.display(window);
		window.display();
	}
}

void AlgorithmVisualise::handleInput(sf::Event & event, sf::Vector2f mousePos)
{

	if (gui.textButtons[0].isChecked(event, mousePos) && !start)
	{
		sortAlgorithm = AlgorithmFactory::getAlgorithm(selectSort);
		sortAlgorithm->setVisual(barGraph);
		sortAlgorithm->setSound(buffer);
		barGraph.reset();
		barGraph.shuffle();
		start = true;
	}
	else if (gui.textButtons[1].isChecked(event, mousePos))
	{
		start = false;
	}
	else if (gui.textButtons[2].isChecked(event, mousePos))
	{
		barGraph.shuffle();
	}
	else if (gui.textButtons[3].isChecked(event, mousePos))
	{
		barGraph.reset();
	}
}

void AlgorithmVisualise::updateData()
{
	barGraph.data.barNumber = gui.sliders[1].getValue();
	barGraph.data.size.x = gui.sliders[2].getValue();
	barGraph.data.size.y = gui.sliders[3].getValue();
	barGraph.data.distance = gui.sliders[4].getValue();
}
