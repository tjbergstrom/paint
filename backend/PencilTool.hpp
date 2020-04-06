/*
 *
 *	PencilTool creates smooth line while mouse is pressed down.
 *
 */

#include <SFML/Graphics.hpp>
#include <memory>
#include "Tool.hpp"
class PencilTool : public Tool{
	using Tool::Tool;
	public:
		void paintTick(Frame&, sf::Color, sf::Event&) override;
		void scrollAction(sf::Event&) override;
		PencilTool(sf::RenderWindow&);
	private:
		bool _mouseDown = false;
		std::unique_ptr<sf::VertexArray> _line = NULL;
};
