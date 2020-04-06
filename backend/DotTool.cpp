/*
	.cpp file for Dots class.
*/

#include "DotTool.hpp"
using std::make_unique;
using std::unique_ptr;

void DotTool::paintTick(Frame& f, sf::Color c, sf::Event& e) {
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		_circle = make_unique<sf::CircleShape>(sf::CircleShape(_dotRadius));
		sf::Vector2i position = sf::Mouse::getPosition(this->getWindow());
		_circle->setPosition(position.x - _dotRadius, position.y - _dotRadius);
		_circle->setFillColor(c);
		f.addObject(*_circle);
		this->playSound();     
	}
}

void DotTool::scrollAction(sf::Event& e){
	if(e.mouseWheelScroll.delta < 0 && _dotRadius < 50){
		_dotRadius += 5;
	}
	else if(e.mouseWheelScroll.delta > 0 && _dotRadius > 5){
		_dotRadius -= 5;
	}
}

DotTool::DotTool(sf::RenderWindow& f): Tool(f){
	this->getIcon().loadFromFile("assets/brushcursor.png");
	this->initializeSound("assets/bubbles.wav");
	//this->initializeSound("assets/drawEffect.wav");
}


