/*
CS-Paint
UI.hpp
UI class controls the UI for this specific program it is not transportable. Tabmenu and Button classes are.
*/

#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "TabMenu.hpp"
#include "Application.hpp"
#include <string>
#include <vector>
#include <memory>




#ifndef FILE_UI_HPP
#define FILE_UI_CPP

class UI {
public:
	//constructor
	UI(Application &app, sf::RenderWindow &window, Tool &dot, Tool &eraser, Tool &square, Tool &pencil, Tool &line);
	
	//returns vector of every menu in program
	std::vector<TabMenu> getMenus();
	
	//check every button in menu and trigger assosiated functions for those pressed
	void buttonAction();

	//calls draw functions for each menu
	void draw(sf::RenderWindow &window);

	//calls setTexture function for every button in program
	void setButTexture(sf::RenderWindow &window);

	//loads the current selected main menu tab (File, Tools, View, Help)
	void loadTab(sf::RenderWindow &window, Application &app);

	//loads menu background texture
	void loadMenuTexture(sf::Vector2f &position, const std::string &imageFilePath, sf::RenderWindow &window);

private:
	
	std::vector<TabMenu> _menus;   
	std::vector<std::shared_ptr<Button>> _tabs;
	std::vector<std::shared_ptr<Button>> _fileButtons;
	std::vector<std::shared_ptr<Button>> _colorButtons;
	std::vector<std::shared_ptr<Button>> _toolButtons;
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::vector<sf::Vector2i> _menuSizes;
	std::vector<sf::Vector2i> _menuPosition;

};

#endif // !FILE_UI_HPP
