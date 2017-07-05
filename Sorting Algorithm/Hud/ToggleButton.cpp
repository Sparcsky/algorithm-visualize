#include "ToggleButton.h"

ToggleButton::ToggleButton(TextureAtlas & atlas, std::string asset)
	:Widget(atlas,asset)
{
}

ToggleButton::ToggleButton()
{
}

ToggleButton::~ToggleButton()
{
}

bool ToggleButton::isChecked(sf::Event event, sf::Vector2f mousePos)
{ 
	if (isClicked(event,mousePos))
	{
		if (checked) 
		{
			checked = false;
			sprite_.setTextureRect(frames_[0]);
		}
		else if(!checked)
		{
			checked = true;
			sprite_.setTextureRect(frames_[1]);
		}
		return checked;
	}
}
