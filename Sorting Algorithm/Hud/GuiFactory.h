#pragma once
#include "TextButton.h"
#include "ItemList.h"
#include "Slider.h"
#include "ToggleButton.h"

using namespace sf;

class GuiFactory
{
public:
	GuiFactory();
	~GuiFactory();

	TextButton makeTextButton(Font *font, TextureAtlas & atlas, std::string asset, std::string name, Vector2f pos, Vector2f size);
	ToggleButton makeToggle(TextureAtlas &atlas, std::string name, Vector2f pos, Vector2f size);
	ItemList makeItemList(TextureAtlas &t, std::string asset,  Vector2f pos, Vector2f size);
	Slider makeSlide(int value, Font * font, TextureAtlas & atlas, std::string scroll, std::string box, Vector2f pos, Vector2f size);
	Text makeText(Font *font, std::string str, int size, Vector2f pos);
	Text makeText(Font *font, int size);
	Sprite makePanel(TextureAtlas &atlas, std::string name, Vector2f pos, Vector2f size);
};

