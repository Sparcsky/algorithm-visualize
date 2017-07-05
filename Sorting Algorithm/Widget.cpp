#include "Widget.h"
#include <iostream>
Widget::Widget(TextureAtlas &atlas,std::string asset)
{
	frames_ = atlas.findRegion(asset);
	sprite_.setTexture(atlas.getTexture());
	sprite_.setTextureRect(frames_[0]);
}

Widget::Widget(sf::Texture & texture, sf::IntRect rect)

{
	sprite_.setTexture(texture);
	sprite_.setTextureRect(rect);
}

Widget::Widget(TextureAtlas & atlas)
{

}


Widget::Widget()
{
}

Widget::~Widget()
{
}

void Widget::draw(sf::RenderWindow & window)
{
	window.draw(sprite_);
}

void Widget::setPosition(sf::Vector2f pos)
{
	sprite_.setPosition(pos);
}
bool Widget::isHover(sf::Vector2f mousePos)
{
	if (mousePos.x > sprite_.getGlobalBounds().left && mousePos.x < sprite_.getGlobalBounds().left + sprite_.getGlobalBounds().width
		&& mousePos.y > sprite_.getGlobalBounds().top && mousePos.y < sprite_.getGlobalBounds().top + sprite_.getGlobalBounds().height) 
	{

		return true;
	}
	return false;
}

void Widget::setVisible(bool flag)
{
	visible_ = flag;
	if (flag) sprite_.setColor(sf::Color(255, 255, 255, 0));
	else sprite_.setColor(sf::Color(255, 255, 255, 255));
}

void Widget::scale(float x, float y)
{
	sprite_.setScale(x, y);
}

bool Widget::isClicked(sf::Event &e, sf::Vector2f mousePos)
{
	if (isHover(mousePos) && e.type == sf::Event::MouseButtonPressed  && e.mouseButton.button == sf::Mouse::Button::Left)
	{
			return true;
	}
	return false;
}

bool Widget::isVisible()
{
	return visible_;
}

float Widget::getHeight()
{
	return sprite_.getGlobalBounds().height;
}

float Widget::getWidth()
{
	return sprite_.getGlobalBounds().width;
}

sf::Vector2f Widget::getPosition()
{
	return sprite_.getPosition();
}

