/*
TabMenu.hpp
CS-Paint
*/
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <string>
#include <vector>
#include <memory>


#ifndef FILE_TABMENU_HPP
#define FILE_TABMENU_HPP

class TabMenu {
public:
	std::vector<std::shared_ptr<Button>> _buttons;

	TabMenu(const sf::Vector2i &position, std::vector<std::shared_ptr<Button>> &buttons);
	

	//draw
	void draw(sf::RenderWindow &window);

	//getters
	int getMenuSize();

	//setters
	void setButtonTextures();

private:
	sf::Vector2i _position;
	
};

#endif /*FILE_TABMENU_HPP*/
