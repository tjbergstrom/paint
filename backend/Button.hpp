/*
	Button.hpp
*/

#include <SFML/Graphics.hpp>
#include <string>
#include<queue>
#include<functional>
#ifndef FILE_BUTTON_HPP
#define FILE_BUTTON_HPP

void delayTime(sf::Clock clock, float seconds);

class Button{
	public:
		enum _ButtonType { AUTO_TOGGLE, CLICK_ON_CLICK_OFF, OFF_BY_CLICK_ANOTHER };
		enum _ButtonState { PRESSED, HOVER, NOT_PRESSED };
		Button();
		//constructor with no text//
		Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &imagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f);
		//constructor with text, but no font or font color (defaults to DejaVuSans and black)//
		Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f, const std::string &text);
		//constructor with text and font but no font color (defaults to black)//
		Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f, const std::string &text, const sf::Font &font);
		//constructor with text, font, and font color//
		Button(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f, const std::string &text, sf::Font font, sf::Color textColor);
		void drawButton(sf::RenderWindow &window);
		sf::Vector2i getPosition();
		sf::Vector2f getSize();
		sf::Text getText();
		_ButtonState getState();
		bool getPressed();
		_ButtonState getButtonState(const sf::RenderWindow &window, sf::Vector2i _menuSize, sf::Vector2i _menuPosition);
		void setState(_ButtonState state);
		void setPosition(sf::Vector2i position);
		void setPressed(bool pressed);
		void setTexture(_ButtonState state);
		void action();
		void setButtonVariables(float length, float width, float xPos, float yPos, bool pressed, const std::string &imagePathNotPressed, const std::string &inmagePathPressed, const std::string &imagePathHover, _ButtonType type, std::function< void()> f, const std::string &text);
	private:
		sf::Vector2f _size;
		sf::Vector2i _position;
		std::string _imagePathNotPressed;
		std::string _imagePathPressed;
		std::string _imagePathHover;
		sf::Texture _texture;
		sf::Sprite _sprite;
		sf::Text _text;
		sf::Font _font;
		_ButtonType _type;
		_ButtonState _state;
		bool _pressed;
		int currentButtonPressed;
		std::function<void(void)> _f;
};

#endif


