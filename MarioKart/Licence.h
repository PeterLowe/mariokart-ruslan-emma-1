#ifndef LICENCE_H
#define LICENCE_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author Ruslan Gavrilov
/// @version 1.0
/// @date Feb2022
/// 
/// \brief simple page to display Licence text for fixed period.
/// 
/// </summary>

class Licence
{
public:
	Licence();
	~Licence();	
	void initilise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void updateTime(sf::Time t_deltaTime);

protected:
	sf::Font m_font;
	sf::Text m_message;
	sf::Time m_timer;

};

#endif // !LICENCE_H