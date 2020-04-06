/*
	Dots tool creates line of circles, is derived from Tool class.
*/

#include "Tool.hpp"
#include <memory>
#ifndef DOTTOOL_HPP_
#define DOTTOOL_HPP_

class DotTool : public Tool{
	using Tool::Tool;
	public:
		DotTool(sf::RenderWindow&);
		void paintTick(Frame&, sf::Color, sf::Event& e) override;
		void scrollAction(sf::Event&) override;
	private:
		int _dotRadius = 5;
		std::unique_ptr<sf::CircleShape> _circle = NULL;
};

#endif


