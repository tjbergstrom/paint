/*
	.cpp file for Tool class.
*/
#include "Tool.hpp"
#include <iostream>
using std::string;

Tool::Tool(sf::RenderWindow& w): _window{w}{}

Tool::~Tool(){
}

sf::RenderWindow& Tool::getWindow() const{
	return _window;
}

sf::Texture& Tool::getIcon() {
	return _mouseIcon;
}
sf::Sound& Tool::getSoundEffect(){ ///////////////////////////////////////temp turning off due to link errors
	return _sfx;
}
void Tool::initializeSound(string s){
	_sfxBuffer.loadFromFile(s);
	_sfx.setBuffer(_sfxBuffer);	
}
void Tool::playSound(){
	if(_sfxCounter % 50 == 0){
		_sfx.play();
	}
	++_sfxCounter;
}
