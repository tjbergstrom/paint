/*
	Application object tracks high-level object such as the current tool, 
	current frame, and playing animations.
*/

#include <SFML/Graphics.hpp>
#include <vector>
#include "Frame.hpp"
#include "Tool.hpp"
#ifndef APP_HPP_
#define APP_HPP_

class Application{
	public:
		void drawCurrentFrame();
		void cycleNextFrame();
		void cycleLastFrame();
		void createNewFrame(int, int);
		void addToFrame(sf::Drawable&);
		Frame* getCurrentFrame(); 
		void setColor(sf::Color);
		sf::Color getColor();
		Tool* getTool();
		void setTool(Tool*);
		sf::RenderWindow& getWindow() const;
		void clearCurrentFrame();
		void close();
		void display();
		Application(sf::RenderWindow&, int w, int h);
		~Application();
		void save();
	private:
		std::vector<Frame*> _frames;
		Frame*  _framePtr = NULL; 
		int _currentFrameIndex = 0;
		sf::Color _currentColor = sf::Color::Black;
		sf::RenderWindow& _window;
		Tool* _currentTool = NULL;
};

#endif


