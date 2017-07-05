#pragma once
#include "Widget.h"
class Slider :
	public Widget
{
public:
	Slider(sf::Font &font,TextureAtlas &atlas, std::string slider,std::string box);
	Slider();
	~Slider();

	void act(sf::Vector2f mousePos);
	void setValue(float value);
	virtual void scale(float x, float y) override;
	virtual void setPosition(sf::Vector2f pos) override;
	virtual void draw(sf::RenderWindow &window) override;
	void setValue(int min, int max);
	float getValue();
	float getX();
	float getY();

private:
	sf::Sprite sliderBox;
	sf::Vector2f sliderPos;
	sf::Text txtValue;
	float value_ = 0.00f;
	int min_ = 0, max_ = 0;
	int temp = 0;
};

