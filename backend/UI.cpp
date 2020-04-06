/*
	UI.cpp
*/

#include "UI.hpp"
#include "Application.hpp"
#include "DotTool.hpp"
#include "EraserTool.hpp"
#include "StraightLineTool.hpp"
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <string>
using std::string;

std::vector<TabMenu> UI::getMenus() {
	return _menus;
}

//make all buttons and the main tabmenu
UI::UI(Application &app, sf::RenderWindow &window, Tool &dot, Tool &eraserTool, Tool &squareTool, Tool &pencilTool, Tool &sLine) {
	auto tab1 = make_shared<Button>(68, 30, 0, 0, false, "assets/tab_not_pressed.png", "assets/tab_pressed.png", "assets/tab_hover.png", Button::OFF_BY_CLICK_ANOTHER, []() { }, " File");
	auto tab2 = make_shared<Button>(68, 30, 68, 0, true, "assets/tab_not_pressed.png", "assets/tab_pressed.png", "assets/tab_hover.png", Button::OFF_BY_CLICK_ANOTHER, []() { }, "Tools");
	auto tab3 = make_shared<Button>(68, 30, 136, 0, false, "assets/tab_not_pressed.png", "assets/tab_pressed.png", "assets/tab_hover.png", Button::OFF_BY_CLICK_ANOTHER, []() { }, "View");
	auto tab4 = make_shared<Button>(68, 30, 204, 0, false, "assets/helpTabImage_not_pressed.png", "assets/helpTabImage_pressed.png", "assets/helpTabImage_hover.png", Button::OFF_BY_CLICK_ANOTHER, []() { }, "Help");
	tab2->setState(Button::PRESSED);
	_tabs.push_back(tab1);
	_tabs.push_back(tab2);
	_tabs.push_back(tab3);
	_tabs.push_back(tab4);	
																													
	// file menu buttons
	auto fileMenuBut1 = make_shared<Button>(90, 30, 0, 35, false, "assets/button_not_pressed_90.png", "assets/button_pressed_90.png", "assets/button_hover_90.png", Button::AUTO_TOGGLE, []() { }, "  New");
	auto fileMenuBut2 = make_shared<Button>(90, 30, 0, 70, false, "assets/button_not_pressed_90.png", "assets/button_pressed_90.png", "assets/button_hover_90.png", Button::AUTO_TOGGLE, []() { }, "  Open");
	auto fileMenuBut3 = make_shared<Button>(90, 30, 0, 105, false, "assets/button_not_pressed_90.png", "assets/button_pressed_90.png", "assets/button_hover_90.png", Button::AUTO_TOGGLE, [&]() {app.save(); }, "  Save");
	auto fileMenuBut4 = make_shared<Button>(90, 30, 0, 140, false, "assets/button_not_pressed_90.png", "assets/button_pressed_90.png", "assets/button_hover_90.png", Button::AUTO_TOGGLE, []() { }, "Save As");
	auto fileMenuBut5 = make_shared<Button>(90, 30, 0, 175, false, "assets/button_not_pressed_90.png", "assets/button_pressed_90.png", "assets/button_hover_90.png", Button::CLICK_ON_CLICK_OFF, [&]() {sf::Vector2f v = { 0,300 }; loadMenuTexture(v, "assets/aboutPageImage.png", window); }, " About");
	auto fileMenuBut6 = make_shared<Button>(90, 30, 0, 215, false, "assets/button_not_pressed_90.png", "assets/button_pressed_90.png", "assets/button_hover_90.png", Button::AUTO_TOGGLE, [&]() {app.close(); }, "   Exit");
	_fileButtons.push_back(fileMenuBut1);
	_fileButtons.push_back(fileMenuBut2);
	_fileButtons.push_back(fileMenuBut3);
	_fileButtons.push_back(fileMenuBut4);
	_fileButtons.push_back(fileMenuBut5);
	_fileButtons.push_back(fileMenuBut6);
	
	// tool menu buttons																															
	auto pencil = make_shared<Button>(40, 40, 56, 110, false, "assets/pencilIcon_not_pressed.png", "assets/pencilIcon_pressed.png", "assets/pencilIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {app.setTool(&pencilTool); });
	auto brush = make_shared<Button>(40, 40, 96, 110, false, "assets/brushIcon_not_pressed.png", "assets/brushIcon_pressed.png", "assets/brushIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, []{});
	auto dotBrush = make_shared<Button>(40, 40, 136, 110, false, "assets/dotBrushIcon_not_pressed.png", "assets/dotBrushIcon_pressed.png", "assets/dotBrushIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {app.setTool(&dot); });
	auto squareBrush = make_shared<Button>(40, 40, 176, 110, false, "assets/sLineIcon_not_pressed.png", "assets/sLineIcon_pressed.png", "assets/sLineIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {app.setTool(&sLine); });
	auto fhSelector = make_shared<Button>(40, 40, 56, 150, false, "assets/fhSelectorIcon_not_pressed.png", "assets/fhSelectorIcon_pressed.png", "assets/fhSelectorIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, []() { });
	auto selector = make_shared<Button>(40, 40, 96, 150, false, "assets/selectorIcon_not_pressed.png", "assets/selectorIcon_pressed.png", "assets/selectorIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, []() { });
	auto eraser = make_shared<Button>(40, 40, 136, 150, false, "assets/eraserIcon_not_pressed.png", "assets/eraserIcon_pressed.png", "assets/eraserIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {app.setTool(&eraserTool); }); 
	//auto circle = make_shared<Button>(40, 40, 176, 150, false, "assets/circleIcon_not_pressed.png", "assets/circleIcon_pressed.png", "assets/circleIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, []() { });
	auto square = make_shared<Button>(40, 40, 176, 150, false, "assets/squareIcon_not_pressed.png", "assets/squareIcon_pressed.png", "assets/squareIcon_hover.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {app.setTool(&squareTool); });
	pencil->setState(Button::PRESSED);
	_toolButtons.push_back(pencil);
	_toolButtons.push_back(dotBrush);
	_toolButtons.push_back(squareBrush);
	_toolButtons.push_back(brush);
	_toolButtons.push_back(fhSelector);
	_toolButtons.push_back(selector);
	//_toolButtons.push_back(circle);
	_toolButtons.push_back(square);
	_toolButtons.push_back(eraser);

	// color menu buttons
	auto black = make_shared<Button>(40, 40, 36, 390, false, "assets/blackIcon.png", "assets/blackIcon.png", "assets/blackIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {app.setColor(sf::Color::Black); });
	auto grey = make_shared<Button>(40, 40, 36, 430, false, "assets/greyIcon.png", "assets/greyIcon.png", "assets/greyicon.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {sf::Color grey(102, 102, 102); app.setColor(grey); });
	auto lightRed = make_shared<Button>(40, 40, 76, 390, false, "assets/lightRedIcon.png", "assets/lightRedIcon.png", "assets/lightRedIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&](){sf::Color lightRed(225, 51, 51); app.setColor(lightRed);  });
	auto darkRed = make_shared<Button>(40, 40, 76, 430, false, "assets/darkRedIcon.png", "assets/darkRedIcon.png", "assets/darkRedIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&]() {sf::Color darkRed(153, 0, 0); app.setColor(darkRed); });
	auto orange = make_shared<Button>(40, 40, 116, 390, false, "assets/orangeIcon.png", "assets/orangeIcon.png", "assets/orangeIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&](){ sf::Color orange(225, 102, 51);	app.setColor(orange); });
	auto yellow = make_shared<Button>(40, 40, 116, 430, false, "assets/yellowIcon.png", "assets/yellowIcon.png", "assets/yellowIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&](){ sf::Color yellow(225, 255, 0); app.setColor(yellow); });
	auto green = make_shared<Button>(40, 40, 156, 390, false, "assets/greenIcon.png", "assets/greenIcon.png", "assets/greenIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&]() { sf::Color green(51, 153, 51); app.setColor(green); });
	auto darkBlue = make_shared<Button>(40, 40, 156, 430, false, "assets/darkBlueIcon.png", "assets/darkBlueIcon.png", "assets/darkBlueIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&]() { sf::Color blue(51, 51, 204); app.setColor(blue); });
	auto lightBlue = make_shared<Button>(40, 40, 196, 390, false, "assets/lightBlueIcon.png", "assets/lightBlueIcon.png", "assets/lightBlueIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&]() { sf::Color lightBlue(0, 153, 255); app.setColor(lightBlue); });
	auto purple = make_shared<Button>(40, 40, 196, 430, false, "assets/purpleIcon.png", "assets/purpleIcon.png", "assets/purpleIcon.png", Button::OFF_BY_CLICK_ANOTHER, [&]() { sf::Color purple(153, 51, 153);	app.setColor(purple); });
	_colorButtons.push_back(black);
	_colorButtons.push_back(grey);
	_colorButtons.push_back(lightRed);
	_colorButtons.push_back(darkRed);
	_colorButtons.push_back(orange);
	_colorButtons.push_back(yellow);
	_colorButtons.push_back(green);
	_colorButtons.push_back(darkBlue);
	_colorButtons.push_back(lightBlue);
	_colorButtons.push_back(purple);

	// tab menus
	TabMenu tabMenu({ 0,0 }, _tabs);
	_menus = { tabMenu };
	_menuSizes = { {273,30} };   
	_menuPosition = { {0,0} };								  
}

// load the current tab and its buttons or submenus
void UI::loadTab(sf::RenderWindow &window, Application &app) {
	// File Tab
	if (_tabs[0]->getState() == Button::PRESSED) {
		TabMenu fileMenu({ 0,30 }, _fileButtons);
		sf::Vector2f menuPosition = { 0,30 };
		this->loadMenuTexture(menuPosition, "assets/tabMenuBackgroundImage.png", window);
		if (_menus.size() < 2) {
			_menus.push_back(fileMenu);
			_menuSizes.push_back({ 273,720 });
			_menuPosition.push_back({ 0,30 });
		}
		else {
			_menus[1] = fileMenu;
			_menuSizes[1] = { 273,720 };
			_menuPosition[1] = { 0, 30 };
		}
		while (_menus.size() > 2) {
			_menus.pop_back();
			_menuSizes.pop_back();
			_menuPosition.pop_back();
		}
	}
	// Tools Tab
	else if (_tabs[1]->getState() == Button::PRESSED) {
		//tool bar
		TabMenu toolMenu({ 56,110 }, _toolButtons);
		sf::Vector2f menuPosition = { 0,0 };
		this->loadMenuTexture(menuPosition, "assets/tabMenuBackgroundImage.png", window);
		if (_menus.size() < 2) {
			_menus.push_back(toolMenu);
			_menuSizes.push_back({ 160, 80 });
			_menuPosition.push_back({ 56, 110});
		}
		else {
			_menus[1] = toolMenu;
			_menuSizes[1] = { 160,80 };
			_menuPosition[1] = { 56, 110 };
		}
		// color picker menu
		TabMenu colorMenu({ 36,390 }, _colorButtons);
		if (_menus.size() < 3) {
			_menus.push_back(colorMenu);
			_menuSizes.push_back({ 200, 80});
			_menuPosition.push_back({ 36,390 });
		}
		else {
			_menus[2] = colorMenu;
			_menuSizes[2] = { 200,80 };
			_menuPosition[2] = { 36,390 };
		}
		// show current color selection
		sf::RectangleShape currentColor;
		currentColor.setOutlineThickness((float)1);
		currentColor.setOutlineColor(sf::Color::Black);
		currentColor.setSize({ (float)80, (float)80 });
		currentColor.setPosition({ (float)96.5, (float)300 });
		currentColor.setFillColor(app.getColor());
		window.draw(currentColor);
	}
	// View Tab
	else if (_tabs[2]->getState() == Button::PRESSED) {
		vector<shared_ptr<Button>> noButtons;
		TabMenu viewMenu({ 0,30 }, noButtons);
		sf::Vector2f menuPosition = { 0,30 };
		this->loadMenuTexture(menuPosition , "assets/viewTabImage.png", window);
		if (_menus.size() < 2) {
			_menus.push_back(viewMenu);
			_menuSizes.push_back({ 273,720 });
			_menuPosition.push_back({ 0,30 });
		}
		else {
			_menus[1] = viewMenu;
			_menuSizes[1] = { 273,720 };
			_menuPosition[1] = { 0, 30 };
		}
		_menus[1] = viewMenu;
		while (_menus.size() > 2) {
			_menus.pop_back();
			_menuSizes.pop_back();
			_menuPosition.pop_back();
		}
	}
	// Help Tab
	else if (_tabs[3]->getState() == Button::PRESSED) {
		sf::Vector2f menuPosition = { 0,30 };
		this->loadMenuTexture(menuPosition, "assets/helpTabBackground.png", window);
		while (_menus.size() > 1) {
			_menus.pop_back();
			_menuSizes.pop_back();
			_menuPosition.pop_back();
		}
	}
}

void UI::buttonAction() {
	for (auto menu = 0; menu < _menus.size(); ++menu) {
		for (auto button = 0; button < _menus[menu]._buttons.size(); ++button) {
			if (_menus[menu]._buttons[button]->getPressed()) {
				_menus[menu]._buttons[button]->action();
			}
		}
	}
}

void UI::draw(sf::RenderWindow &window) {
	int m = 0;
	for (auto menu : _menus){
		menu.draw(window);
	}
}

void UI::setButTexture(sf::RenderWindow &window) {
	for (auto menu = 0; menu < _menus.size(); ++menu) {
		for (auto button = 0; button < _menus[menu]._buttons.size(); ++button) {
			_menus[menu]._buttons[button]->setTexture(_menus[menu]._buttons[button]->getButtonState(window, { _menuSizes[menu].x, _menuSizes[menu].y}, {_menuPosition[menu].x, _menuPosition[menu].y }));
		}
	}
}

void UI::loadMenuTexture(sf::Vector2f &position, const std::string &imageFilePath, sf::RenderWindow &window) {
	if (!_texture.loadFromFile(imageFilePath))
	{
		// error check
	}
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setPosition(position.x, position.y);
	window.draw(_sprite);
}


