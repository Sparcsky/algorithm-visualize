#include "Slider.h"

Slider::Slider(sf::Font & font, TextureAtlas & atlas, std::string slider, std::string box)
{
	txtValue.setCharacterSize(14);
	txtValue.setFont(font);
	txtValue.setString(std::to_string(max_));
	txtValue.setOrigin(txtValue.getOrigin().x, txtValue.getGlobalBounds().height / 2);

	sprite_.setTexture(atlas.getTexture());
	sprite_.setTextureRect(atlas.getImage(slider));
	sprite_.setOrigin(getWidth() / 2, (getHeight()) / 2);
	sprite_.setColor(sf::Color(255, 255, 255, 100));

	sliderBox.setTexture(atlas.getTexture());
	sliderBox.setTextureRect(atlas.getImage(box));
	sliderBox.setOrigin(sliderBox.getOrigin().x, sliderBox.getGlobalBounds().height / 2);
}

Slider::Slider()
{
}


Slider::~Slider()
{

}


void Slider::act(sf::Vector2f mousePos)
{
	if (isHover(mousePos))
	{
		if (mousePos.x > getX() && mousePos.x < sliderBox.getGlobalBounds().width + getX())
		{
			/*	lerp(x, a, b) = a*(1 - x) + x*b;
			invlerp(y, a, b) = (y - a) / (b - a)*/

			sliderPos.y = sliderBox.getPosition().y;
			sliderPos.x = mousePos.x;

			double invlerp = ((sliderPos.x - sliderBox.getPosition().x)) / (sliderBox.getGlobalBounds().width);
			value_ = min_ * (1 - invlerp) + invlerp * max_;

			sprite_.setPosition(mousePos.x, sliderPos.y);
			txtValue.setString(std::to_string(value_).substr(0, 4));
		}
	}
}

void Slider::setValue(float value)
{
	min_ = 0;
	max_ = value;
}

void Slider::scale(float x, float y)
{
	sliderBox.scale(x, y);
}

void Slider::setPosition(sf::Vector2f pos)
{
	sliderBox.setPosition(pos.x, pos.y);
	sprite_.setPosition(pos.x,pos.y);
	txtValue.setPosition(10 + pos.x + sliderBox.getGlobalBounds().width, pos.y - txtValue.getCharacterSize() / 2);
}

void Slider::draw(sf::RenderWindow & window)
{

	window.draw(sliderBox);
	window.draw(sprite_);
	window.draw(txtValue);
}

void Slider::setValue(int min, int max)
{
	min_ = min;
	max_ = max;
}

float Slider::getValue()
{
	return value_;
}

float Slider::getX()
{
	return sliderBox.getPosition().x;
}

float Slider::getY()
{
	return sliderBox.getPosition().y;
}
