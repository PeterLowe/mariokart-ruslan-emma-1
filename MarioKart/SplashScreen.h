#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author RuslanGavrrilov
/// @version 1.0
/// @date February2022
/// 
/// Simple class to display full screen texture
/// and text message and wait for anykey
/// </summary>
class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	

protected:
	sf::Font m_font;
	sf::Text m_message;

	int m_splashTimer = 0;
};

#endif // !SPLASHSCREEN_H
