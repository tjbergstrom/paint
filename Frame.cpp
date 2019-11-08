/*
	.cpp file for Frame class.
*/

#include "Frame.hpp"

Frame::Frame(sf::RenderWindow& window, int w, int h): _window{window}{
	_texture.create(w,h);
	_sprite.setColor(sf::Color::White);
}
void Frame::clear(){
	_window.clear(sf::Color::White);
	_texture.update(_window);
	_sprite.setTexture(_texture);
}
void Frame::addObject(sf::Drawable& s){
	_window.clear(sf::Color::White);
	_window.draw(_sprite);
	_window.draw(s);
	_texture.update(_window);
	_sprite.setTexture(_texture);
}
void Frame::drawObjects(){
	_window.draw(_sprite);
}
sf::RenderWindow& Frame::getWindow(){
	return _window;
}
Frame::~Frame(){}
