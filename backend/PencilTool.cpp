/*
 	.cpp file for PencilTool class.
 */

#include "PencilTool.hpp"
using std::make_unique;

void PencilTool::paintTick(Frame& f, sf::Color c, sf::Event& e){
	if(e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left){
		_mouseDown = true;
		_line = make_unique<sf::VertexArray>(sf::VertexArray(sf::LinesStrip));
	}
	else if(e.type == sf::Event::MouseMoved && _mouseDown){
		sf::Vector2f vertexPos = sf::Vector2f(sf::Mouse::getPosition(this->getWindow()));
		_line->append(sf::Vertex(vertexPos,c));
		this->playSound();
		f.addObject(*_line);
	}
	else if(e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left){
		_mouseDown = false;
	}
}

void PencilTool::scrollAction(sf::Event& e){
}

PencilTool::PencilTool(sf::RenderWindow& w): Tool(w){
	this->getIcon().loadFromFile("assets/pencilCursor.png");
	this->initializeSound("assets/drawEffect.wav");
}


