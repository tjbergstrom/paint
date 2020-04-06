/*
	Frame class is responsible for storing, displaying, or clearing current Frame
*/

#include <SFML/Graphics.hpp>
#ifndef FRAME_HPP_
#define FRAME_HPP_

class Frame{
	public:
		Frame(sf::RenderWindow&, int w, int h);
		void clear();
		void addObject(sf::Drawable&);
		void drawObjects();
		sf::RenderWindow& getWindow();
		~Frame();
	private:
		sf::Texture _texture;
		sf::Sprite _sprite;
		sf::RenderWindow& _window;
};

#endif


