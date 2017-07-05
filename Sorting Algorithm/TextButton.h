#pragma once
#include <memory>
#include "Widget.h"

class TextButton : public Widget
{
public:


	TextButton(TextureAtlas &atlas, std::string asset);
	TextButton();
	~TextButton();

	virtual void draw(sf::RenderWindow &window) override;
	virtual void setPosition(sf::Vector2f pos)override;
	virtual void scale(float x, float y)override;

	bool isChecked(sf::Event & e, sf::Vector2f mousePos);
	void setString(std::string title);
	void textSettings(sf::Font &font, std::string txt, int size);

	bool disable = false;
	bool checked = true;

protected:
	sf::Text text;
	sf::Vector2f defPos;

};

