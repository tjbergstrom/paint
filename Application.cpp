/*
	.cpp for Application object.
*/

#include "Application.hpp"

void Application::drawCurrentFrame(){
	_frames[_currentFrameIndex]->drawObjects();
}
void Application::cycleNextFrame(){
	if(_currentFrameIndex < _frames.size()-1){
		++_currentFrameIndex;
	}
}
void Application::cycleLastFrame(){
	if(_currentFrameIndex > 0){
		--_currentFrameIndex;
	}
}
void Application::createNewFrame(int w, int h){
	_framePtr = new Frame(this->getWindow(), w, h);
	_frames.push_back(_framePtr);
}
void Application::setColor(sf::Color c){
	_currentColor = c;
}

sf::Color Application::getColor(){
	return _currentColor;
}

void Application::setTool(Tool* t){ 
	_currentTool = t;
}
Tool* Application::getTool(){ 
	return _currentTool;
}
sf::RenderWindow& Application::getWindow() const{
	return _window;
}
void Application::clearCurrentFrame(){
	_frames[_currentFrameIndex]->clear();
}
void Application::addToFrame(sf::Drawable& d){
	_frames[_currentFrameIndex]->addObject(d);
}
Frame* Application::getCurrentFrame(){
	return _frames[_currentFrameIndex];
}
void Application::close(){
	_window.close();
}
void Application::display(){
	_window.display();
}
void Application::save(){
	this->drawCurrentFrame();
	sf::Texture screenTexture;
	auto dimensions = _window.getSize();
	screenTexture.create(dimensions.x, dimensions.y);
	screenTexture.update(this->getWindow());
	sf::Image screenshot = screenTexture.copyToImage();
	screenshot.saveToFile("saved/screenshot.jpg");
}
Application::Application(sf::RenderWindow& window, int w, int h):_window{window}{
	createNewFrame( w,  h);
}
Application::~Application(){}
