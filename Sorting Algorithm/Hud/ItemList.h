#pragma once
#include "Widget.h"
#include <vector>
class ItemList : public Widget
{
public:
	 ItemList(TextureAtlas &atlas,std::string asset);
	 ItemList();
	 ~ItemList();

	std::string selectItem(sf::Vector2f mousePos);

	virtual void draw(sf::RenderWindow &window);

	virtual void setVisible(bool flag) override;
	void settings(sf::Font &font,std::string title, std::vector<std::string>names, float scaleX);
	void insert(std::string name);

private:

	std::vector<sf::Text> list;
	sf::Text title;
	sf::RectangleShape line,selector;
	sf::Vector2f selectorPos;
	int selectIndex = 0;
};

