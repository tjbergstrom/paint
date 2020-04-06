/*
	SquareTool creates solid square of given color of dimensions created by user's
	click-and-drag.
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "Tool.hpp"

class SquareTool : public Tool{
	using Tool::Tool;
	public:
		void paintTick(Frame&, sf::Color, sf::Event&) override;
		void scrollAction(sf::Event&) override;
		SquareTool(sf::RenderWindow&);
	private:
		bool _mouseDown = false;
		std::unique_ptr<sf::RectangleShape> _square = NULL;
		sf::Vector2i _startPos;
		float _outlineThickness = 10;
};
