#pragma once
#include "Widget.h"

class ToggleButton :
	public Widget
{
public:
	ToggleButton(TextureAtlas &atlas,std::string asset);
	ToggleButton();
	~ToggleButton();

	bool isChecked(sf::Event  e, sf::Vector2f mousePos);
	bool checked = false;

private:
};

