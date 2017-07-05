#include "GuiFactory.h"

GuiFactory::GuiFactory()
{
}


GuiFactory::~GuiFactory()
{
}

TextButton GuiFactory::makeTextButton(Font *font, TextureAtlas & atlas, std::string asset, std::string name, Vector2f pos, Vector2f size)
{
	TextButton textBotton(atlas, asset);
	textBotton.textSettings(*font, name, 14);
	textBotton.scale(size.x, size.y);
	textBotton.setPosition(pos);
	return textBotton;
}

ToggleButton GuiFactory::makeToggle(TextureAtlas & atlas, std::string name, Vector2f pos, Vector2f size)
{
	ToggleButton toggleButton(atlas, name);
	toggleButton.setPosition(pos);
	toggleButton.scale(size.x, size.y);
	return toggleButton;
}


ItemList GuiFactory::makeItemList(TextureAtlas & atlas, std::string asset, Vector2f pos, Vector2f size)
{
	ItemList list(atlas, asset);
	list.setPosition(pos);
	list.scale(size.x, size.y);
	return list;
}

Slider GuiFactory::makeSlide(int value,Font * font, TextureAtlas & atlas, std::string scroll, std::string box, Vector2f pos, Vector2f size)
{
	Slider slider(*font, atlas, scroll, box);
	slider.setValue(value);
	slider.scale(size.x, size.y);
	slider.setPosition(pos);
	return slider;
}

Text GuiFactory::makeText(Font * font, std::string str, int size, Vector2f pos)
{
	sf::Text text;
	text.setCharacterSize(size);
	text.setFont(*font);
	text.setString(str);
	text.setPosition(pos);
	return text;
}

Text GuiFactory::makeText(Font * font, int size)
{
	sf::Text text;
	text.setCharacterSize(size);
	text.setFont(*font);
	return text;
}

Sprite GuiFactory::makePanel(TextureAtlas & atlas, std::string name, Vector2f pos, Vector2f size)
{
	Sprite sprite(atlas.getTexture());
	sprite.setTextureRect(atlas.getImage(name));
	sprite.setPosition(pos);
	sprite.setScale(size);
	return sprite;
}
