
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <SFML/Graphics.hpp>
#include<iostream>
#include "Game.h"
#include "Licence.h"

/*
Written by Ruslan Gavrilov and Emma McDonald Feb 2022*/


int main()
{ 
	Game game; 
	game.run(); 
}

 
/// <summary>
/// @brief main game constructor creating the render window with settings
/// </summary>
Game::Game() : m_window(sf::VideoMode{ 800U,600U,32U }, "MarioKart", sf::Style::Default)
{			
	drawObjects();
}

/// <summary>
/// @brief main game loop.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{		
			timeSinceLastUpdate -= timePerFrame;

			processEvents();
			update(timePerFrame);		
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time time)
{
	switch (m_currentState)
	{
	case GameState::Licence:
		m_licenceScreen.updateTime(time);
	}
}

void Game::render()
{
	m_window.clear();
	switch (m_currentState)
	{
	case GameState::Licence:
		m_licenceScreen.render(m_window);
		break;
	}
	m_window.display();
}

void Game::drawObjects()
{
	if (!m_font.loadFromFile("ASSETS\\FONTS\\BebasNeue.otf"))
	{
		std::cout << "error loading font" << std::endl;
	}
	m_licenceScreen.initilise(m_font);
}
