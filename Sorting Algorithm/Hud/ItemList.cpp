#include "ItemList.h"

ItemList::ItemList(TextureAtlas &atlas, std::string asset)
	: Widget(atlas,asset)
{
	visible_ = true;

	title.setCharacterSize(14);
	selector.setFillColor(sf::Color(200, 200, 200, 100));
}

ItemList::ItemList()
{
}

ItemList::~ItemList()
{
}

std::string ItemList::selectItem(sf::Vector2f mousePos)
{
	selectorPos = mousePos;

	selector.setPosition(sprite_.getPosition().x, list[selectIndex].getPosition().y);
	return list[selectIndex].getString();
}


void ItemList::setVisible(bool flag)
{
	visible_ = flag;

	if (visible_)
	{
		sf::Color white = sf::Color::White;
		sprite_.setColor(white);
		title.setFillColor(white);
		line.setFillColor(white);
		selector.setFillColor(white);

		selector.setFillColor(sf::Color(100, 100, 100, 100));

		for (size_t i = 0; i < list.size(); i++)
		{
			list[i].setFillColor(sf::Color(255, 255, 255, 255));
		}
	}
	else
	{
		sf::Color none = sf::Color(255, 255, 255, 0);

		sprite_.setColor(none);
		title.setFillColor(none);
		line.setFillColor(none);
		selector.setFillColor(sf::Color(100, 100, 100, 0));

		for (size_t i = 0; i < list.size(); i++)
		{
			list[i].setFillColor(none);
		}
	}
}

void ItemList::settings(sf::Font & font, std::string header, std::vector<std::string>names, float scaleX)
{
	title.setFont(font);
	title.setString(header);

	title.setPosition(sf::Vector2f(sprite_.getPosition().x + (getWidth() - title.getGlobalBounds().width - title.getCharacterSize()) / 2, sprite_.getPosition().y + title.getCharacterSize() / 2));
	line.setSize(sf::Vector2f(sprite_.getGlobalBounds().width, 2));
	line.setPosition(sf::Vector2f(sprite_.getPosition().x, 5 + title.getPosition().y + title.getCharacterSize() + line.getGlobalBounds().height));
	line.setFillColor(sf::Color(208, 208, 208));


	for (size_t i = 0; i < names.size(); i++)
	{
		sf::Text text;
		text.setFont(font);
		text.setString(names[i]);
		text.setCharacterSize(13);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(sprite_.getPosition().x + 7, 10 + title.getGlobalBounds().height * 2 + sprite_.getPosition().y + i * text.getCharacterSize() * 1.5));
		list.push_back(text);
	}

	selector.setPosition(sprite_.getPosition().x, list[selectIndex].getPosition().y);
	selector.setSize(sf::Vector2f(getWidth(), 20));
}


void ItemList::insert(std::string name)
{
}

void ItemList::draw(sf::RenderWindow & window)
{
	window.draw(sprite_);
	window.draw(title);
	window.draw(line);
	for (size_t i = 0; i < list.size(); i++)
	{
		if (selectorPos.x > list[i].getGlobalBounds().left && selectorPos.x < getWidth()
			&& selectorPos.y > list[i].getGlobalBounds().top && selectorPos.y < list[i].getGlobalBounds().top + list[i].getGlobalBounds().height)
		{
			selectIndex = i;
		}

		window.draw(list[i]);
	}
	window.draw(selector);
}
