/*
TabMenu.cpp
CS-Paint
*/
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "TabMenu.hpp"
#include <string>
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;


TabMenu::TabMenu(const sf::Vector2i &position,vector<shared_ptr<Button>> &buttons): _position{ position }, _buttons{ buttons } {
	
}

void TabMenu::draw(sf::RenderWindow &window) {
	for (auto button = 0; button < _buttons.size(); ++button) {
		_buttons[button]->drawButton(window);
	}
}
 
int TabMenu::getMenuSize() {
	return _buttons.size();
}

void TabMenu::setButtonTextures() {
	for (auto button = 0; button < _buttons.size(); ++button) {
		_buttons[button]->setTexture(_buttons[button]->getState());
	}
}

