
#include "Licence.h"
#include "Game.h"
#include<iostream>

Licence::Licence()
{
<<<<<<< HEAD

=======
	
>>>>>>> ruslan
}


Licence::~Licence()
{
}

void Licence::initilise(sf::Font& t_font)
{
	m_font = t_font;

	m_message.setFont(m_font);
	m_message.setFillColor(sf::Color::White);
	m_message.setCharacterSize(50);
	m_message.setPosition(25,25);
	m_message.setString("Emma and Ruslan Inc.");
	m_timer = sf::seconds(0);
}

void Licence::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_message);
}

void Licence::updateTime(sf::Time t_deltaTime)
{
	m_timer += t_deltaTime;
	if (m_timer.asSeconds() > 0.8)
	{
		Game::m_currentState = GameState::Splash;
	}
}

