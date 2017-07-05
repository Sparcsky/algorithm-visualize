#include "Gui.h"

Gui::Gui()
{
	atlas.reset(new TextureAtlas("Assets/GUI.png", "Assets/GUI.txt"));
	font = new sf::Font();
	font->loadFromFile("Assets/molten.ttf");

	std::vector<std::string> lstName = { "Bubble sort","Insertion sort","Selection sort" };
	std::string btnName[] = { "start","edit","shuffle","reset" };
	std::string sldName[] = { "speed","quantity","width","height","gap" };

	for (size_t i = 0; i < 5; i++)
	{
		sliders.push_back(guiFactory.makeSlide(5, font, *atlas, "slider", "sliderBox", Vector2f(300, 20 + (i * 21)), Vector2f(.6f, 1)));
		texts.push_back(guiFactory.makeText(font, sldName[i], 14, Vector2f(225, 12 + (i * 20))));
		if (i < 4)
		{
			int x = i <= 1 ? 220 + (i * 90) : 220 + ((i - 2) * 90);
			int y = i <= 1 ? 125 : 155;
			textButtons.push_back(guiFactory.makeTextButton(font, *atlas, "btn", btnName[i], Vector2f(x, y), Vector2f(1, 1)));
		}
	}
	itemList = ItemList(*atlas, "panel");
	itemList.setPosition(Vector2f(5, 5));
	itemList.scale(.8f, 2.5f);
	itemList.settings(*font, "Sorting Algorithm", lstName, .5f);
	panel.setTexture(atlas->getTexture());
	panel.setTextureRect(atlas->getImage("panel"));
	panel.setPosition(220, 5);
	panel.scale(1.05, 1.1);

}

Gui::~Gui()
{
	delete font;
}

void Gui::updateSlider(sf::Vector2f mousePos)
{
	for (size_t i = 0; i <= 4; i++)
	{
		sliders[i].act(mousePos);
	}
}

void Gui::display(sf::RenderWindow & window)
{

	window.draw(panel);
	itemList.draw(window);
	for (size_t i = 0; i < 5; i++)
	{
		if (i < 4)
			textButtons[i].draw(window);
		sliders[i].draw(window);
		window.draw(texts[i]);
	}

}

