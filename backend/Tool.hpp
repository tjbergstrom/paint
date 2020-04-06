/*
	Tool object is abstract data type inherited by paint tools such as brushes, shapes, etc
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Frame.hpp"
#ifndef TOOL_HPP_
#define TOOL_HPP_

class Tool{
	public:
		virtual void paintTick(Frame&, sf::Color,sf::Event& e)  = 0;
		virtual void scrollAction(sf::Event&) = 0;
		Tool(sf::RenderWindow&);
		sf::RenderWindow& getWindow() const;
		virtual ~Tool();
		sf::Texture& getIcon();
		sf::Sound& getSoundEffect();
		void initializeSound(std::string);
		void playSound();
	private:
		sf::RenderWindow& _window;
		sf::Texture _mouseIcon;
		sf::SoundBuffer _sfxBuffer;
		sf::Sound _sfx;
		int _sfxCounter = 0;
};

#endif


