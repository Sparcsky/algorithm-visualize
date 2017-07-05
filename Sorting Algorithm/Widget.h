#pragma once
#include <SFML\Graphics.hpp>
#include "TextureAtlas.h"
class Widget
{
public:
	Widget(TextureAtlas &atlas,std::string asset);
	Widget(sf::Texture & texture,sf::IntRect rect);
	Widget(TextureAtlas &atlas);
	Widget();
	~Widget();

	virtual void draw(sf::RenderWindow &window);
	virtual void setPosition(sf::Vector2f pos);
	virtual bool isHover(sf::Vector2f mousePos);
	virtual void setVisible(bool flag);
	virtual void scale(float x, float y);
	virtual bool isClicked(sf::Event & e, sf::Vector2f mousePos);

	bool isVisible();
	float getHeight();
	float getWidth();
	sf::Vector2f getPosition();

protected:
	sf::Sprite sprite_;
	std::vector<sf::IntRect> frames_;
	bool visible_ = true;
};

