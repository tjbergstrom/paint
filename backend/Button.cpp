/*
Button.cpp
CS-Paint
*/

#include "Button.hpp"
#include <string>
using std::string;
#include <SFML/System/Clock.hpp>
#include<vector>
using std::vector;
#include<queue>
using std::queue;
#include<functional>
using std::function;

//deafult constructor
Button::Button(){}

//constructor with no text//
Button::Button(float width, float length, float xPos, float yPos, bool pressed, const string &imagePathNotPressed, const string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f)
	: _size{ width, length }, _position{ static_cast<int>(xPos), static_cast<int>(yPos) }, _pressed{ pressed }, _imagePathNotPressed {imagePathNotPressed}, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type{ type }, _f{ f }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_state = NOT_PRESSED;
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setOrigin(0, 0);
	_sprite.setPosition(xPos, yPos);

}

//constructor with text, but not font or font color.//
Button::Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f, const std::string &text)
: _size{ width, length }, _position{ static_cast<int>(xPos), static_cast<int>(yPos) }, _pressed{ pressed }, _imagePathNotPressed {imagePathNotPressed}, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type{ type }, _f{ f }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_state = NOT_PRESSED;
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setPosition(xPos, yPos);
	auto textSize = text.size();
	_text.setPosition(_position.x + /*(length - (textSize))*/  (0.4 * _size.x), _position.y + (0.09 * _size.y));
	_font.loadFromFile("assets/DejaVuSans.ttf");
	_text.setFont(_font);
	_text.setFillColor(sf::Color::Black);
	_text.setString(text);
	_text.scale({ 0.5, 0.5 });

}

//constructor with text and font but no font color//
Button::Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f,  const std::string &text, const sf::Font &font)
	: _size{ width, length }, _position{ static_cast<int>(xPos), static_cast<int>(yPos) }, _pressed{ pressed }, _imagePathNotPressed {imagePathNotPressed}, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type{ type }, _f{ f }, _font{ font }
{

	if (!_texture.loadFromFile(_imagePathNotPressed)) { //set initial button state to not pressed
														// error...
	}
	_state = NOT_PRESSED;
	_sprite.setPosition(xPos, yPos);
	_text.setPosition(_position.x, _position.y);
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_text.setFont(font);
	_text.setFillColor(sf::Color::Black);
	_text.setString(text);
	_text.scale({ 0.5, 0.5 });

}

//constructor with text, font, and font color//
Button::Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f,  const std::string &text, sf::Font font, sf::Color textColor)
	: _size{ width, length }, _position{ static_cast<int>(xPos), static_cast<int>(yPos) }, _pressed{ pressed }, _imagePathNotPressed {imagePathNotPressed}, _imagePathPressed{ imagePathPressed }, _imagePathHover{ imagePathHover }, _type{ type }, _f{ f }, _font{ font }
{
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_state = NOT_PRESSED;
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setPosition(xPos, yPos);
	_text.setFont(_font);
	_text.setFillColor(textColor);
	_text.setString(text);
	_text.scale({ 0.5, 0.5 });
}

//delay time... some buttons are a little too responsive. 
void delayTime(sf::Clock clock, float seconds) {
	sf::Time elapsed = clock.getElapsedTime();
	sf::Time delay = sf::seconds(seconds);
	while (elapsed < delay)
	{
		elapsed = clock.getElapsedTime();
	}
}

//////getters//////
sf::Vector2i Button::getPosition() {
	return _position;
}

sf::Vector2f Button::getSize() {
	return _size;
}

sf::Text Button::getText() {
	return _text;
}

Button::_ButtonState Button::getState() {
	return _state;
}

bool Button::getPressed() {
	return _pressed;
}

//returns true if button is pressed, false if it's not.//  
Button::_ButtonState Button::getButtonState(const sf::RenderWindow &window, sf::Vector2i menuSize, sf::Vector2i menuPosition) {
	sf::Vector2f mousePointRelativeToWorld;
	//Get the mouse position:
	sf::Vector2i mouse = sf::Mouse::getPosition(window);
	//Map Pixel to Coords:
	sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);

	if (_type == OFF_BY_CLICK_ANOTHER) {

		if ((mouse_world.x > menuPosition.x && mouse_world.x < menuPosition.x + menuSize.x) &&
			(mouse_world.y > menuPosition.y && mouse_world.y < menuPosition.y + menuSize.y)) {
			sf::Clock clock; //////////////////////////make member variable?
			

			//turn off button if another is pressed
			if (_state == HOVER /*&& !_pressed*/ && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_pressed = true;
				_state = PRESSED;
				//delayTime(clock, 0.1);
			}
			if (_state == PRESSED && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(!(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) ||
					!(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x))) {
				_pressed = false;
				_state = NOT_PRESSED;
				//delayTime(clock, 0.1);
			}
			
			else if(_state == NOT_PRESSED && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_pressed = false;
				_state = HOVER;
				//delayTime(clock, 0.1);
			}
			else if (_state == HOVER && /*!_pressed &&*/ !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(!(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) ||
					!(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x))) {
				//_pressed = false;
				_state = NOT_PRESSED;
			}
			return _state;
		}
		else
			return _state;
	}

	if (_type == CLICK_ON_CLICK_OFF) {
		sf::Clock clock;
		if (_text.getString() == "") {
			if (_state == PRESSED && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_pressed = false;
				_state = NOT_PRESSED;
			}
			else if (_state == (HOVER || NOT_PRESSED) && !_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_pressed = true;
				_state = PRESSED;
				delayTime(clock, 0.1);
			}
			else if (_state == NOT_PRESSED && !_pressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_state = HOVER;
				delayTime(clock, 0.1);
			}
			else if (_state == HOVER && !_pressed &&
				(!(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) ||
					!(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y))) {
				_state = NOT_PRESSED;
				delayTime(clock, 0.1);
			}
		}

		else { //if there is text
			if (_state == PRESSED && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_pressed = false;
				_state = NOT_PRESSED;
			}
			else if (_state == (HOVER || NOT_PRESSED) && !_pressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_pressed = true;
				_state = PRESSED;
				delayTime(clock, 0.1);
			}
			else if (_state == NOT_PRESSED && !_pressed && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_state = HOVER;
				delayTime(clock, 0.1);
			}
			else if (_state == HOVER && !_pressed &&
				(!(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) ||
					!(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x))) {
				_state = NOT_PRESSED;
				delayTime(clock, 0.1);
			}

		}
		return _state;
	}

	if (_type == AUTO_TOGGLE) {
		sf::Clock clock;
		if (_text.getString() == "") {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_state = PRESSED;
				return _state;
				
			}
			if (_state == NOT_PRESSED && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.x) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.y)) {
				_state = HOVER;
				return _state;
			}
			else {
				_state = NOT_PRESSED;
				return _state;
				
			}
		}
		else {//if there is text
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				_pressed = true;
				return PRESSED;
				
			}
			if (_state == NOT_PRESSED && !sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
				(mouse_world.x > _position.x && mouse_world.x < _position.x + _size.y) &&
				(mouse_world.y > _position.y && mouse_world.y < _position.y + _size.x)) {
				return HOVER;
				
			}
			else {
				_pressed = false;
				return NOT_PRESSED;
				
			}
		}
	}
}

//set button position
void Button::setPosition(sf::Vector2i position) {
	_position = position;
}

void Button::setPressed(bool pressed) {
	_pressed = pressed;
}

//set button state
void Button::setState(Button::_ButtonState state) {
	_state = state;
}

//sets button texture based on pressed/not pressed status//
void Button::setTexture(Button::_ButtonState state) {

	if (state == PRESSED) {
		_texture.loadFromFile(_imagePathPressed);
		{
			// catch error...
		}
	}
	if (state == NOT_PRESSED) {
		_texture.loadFromFile(_imagePathNotPressed);
		{
			//catch error...
		}
	}
	if (state == HOVER) {
		_texture.loadFromFile(_imagePathHover);
		{
			//catch error...
		}
	}

}


//draws button to window//
 void Button::drawButton(sf::RenderWindow &window) {
	window.draw(Button::_sprite);
	window.draw(Button::_text);
	
}

//assigns empty button's member variables
void Button::setButtonVariables(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f, const std::string &text) {
	_size = { width, length };
	_position = { static_cast<int>(xPos), static_cast<int>(yPos) };
	_imagePathNotPressed = imagePathNotPressed;
	_imagePathPressed = imagePathPressed;
	_imagePathHover = imagePathHover;
	_type = type;
	_f = f;
	if (!_texture.loadFromFile(_imagePathNotPressed)) //set initial button state to not pressed
	{
		// error...
	}
	_pressed = pressed;
	_state = NOT_PRESSED;
	_texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setPosition(xPos, yPos);
	_text.setPosition(_position.x + (0.4 * _size.x), _position.y + (0.09 * _size.y));
	_font.loadFromFile("assets/DejaVuSans.ttf");
	_text.setFont(_font);
	_text.setFillColor(sf::Color::Black);
	_text.setString(text);
	_text.scale({ 0.5, 0.5 });

}


void Button::action() {
	_f();
}

