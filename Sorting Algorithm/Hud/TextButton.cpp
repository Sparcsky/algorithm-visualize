#include "TextButton.h"

TextButton::TextButton(TextureAtlas & atlas, std::string asset)
	:Widget(atlas, asset)
{
}

TextButton::TextButton()
{
}

TextButton::~TextButton()
{
}

void TextButton::draw(sf::RenderWindow & window)
{
	window.draw(sprite_);
	window.draw(text);
}
void TextButton::setPosition(sf::Vector2f pos)
{
	sprite_.setPosition(pos);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(pos.x + (sprite_.getGlobalBounds().width / 2), pos.y + ((sprite_.getGlobalBounds().height) / 3));
	defPos = text.getPosition();
}
bool TextButton::isChecked(sf::Event& e, sf::Vector2f mousePos)
{
	if (isClicked(e, mousePos))
	{
		if (!checked)
		{
			sprite_.setTextureRect(frames_[1]);
			text.setPosition(text.getPosition().x - 2, text.getPosition().y + 2);
			checked = true;
		}
		else if (checked && !disable)
		{
			sprite_.setTextureRect(frames_[0]);
			text.setPosition(text.getPosition().x + 2, text.getPosition().y - 2);
			checked = false;
		}
		return checked;
	}
	if (disable && text.getPosition() != defPos)
	{
		sprite_.setTextureRect(frames_[0]);
		text.setPosition(defPos);
		checked = false;
	}
	return false;
}

void TextButton::scale(float x, float y)
{
	sprite_.setScale(x, y);
}

void TextButton::textSettings(sf::Font & font, std::string txt, int size)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setString(txt);
}

void TextButton::setString(std::string title)
{
	text.setString(title);
}

