#include <SFML/Graphics.hpp>
#include <memory>
#include "Tool.hpp"
class StraightLineTool : public Tool{
	using Tool::Tool;
	public:
		void paintTick(Frame&, sf::Color, sf::Event&) override;
		void scrollAction(sf::Event&) override;
		StraightLineTool(sf::RenderWindow&);
	private:
		bool _mouseDown = false;
		std::unique_ptr<sf::VertexArray> _line = NULL;
};
