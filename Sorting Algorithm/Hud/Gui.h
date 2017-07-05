#pragma once
#include <SFML\Graphics.hpp>
#include "GuiFactory.h"
#include "../TextureAtlas.h"

class Gui
{

public:
	ItemList itemList;
	std::vector<TextButton> textButtons;
	std::vector<Slider> sliders;
	std::vector<sf::Text> texts;

	Gui();
	~Gui();

	void display(sf::RenderWindow &window);
	void updateSlider( sf::Vector2f mousePos);


private:
	std::unique_ptr<TextureAtlas> atlas;
	GuiFactory guiFactory;
	sf::Font *font;
	sf::Sprite panel;
	sf::Vector2f mousePos_;
};
