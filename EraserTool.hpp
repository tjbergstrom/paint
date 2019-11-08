/*
	Eraser tool allows client to 'erase' canvas by overwriting with white circles.
*/
#include "Tool.hpp"
#include <memory>
#ifndef ERASER_HPP_
#define ERASER_HPP_
class EraserTool : public Tool{
	using Tool::Tool;
	public:
		EraserTool(sf::RenderWindow&);
		void paintTick(Frame&, sf::Color, sf::Event&) override;
		void scrollAction(sf::Event&) override;
	private:
		std::unique_ptr<sf::CircleShape> _circle = NULL;
		int _dotRadius = 10;
};
#endif
