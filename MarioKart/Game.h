#ifndef GAME_H
#define GAME_H
// Use the vs debug / release mode effect of defineing _DEBUG to turn on/off
// features  used only in degub mode

#include "Licence.h"


/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// @brief main game class conatins main and run game loop.
/// </summary>
/// 
/// 
enum class GameState {
	None,
	Licence,
	Splash,
	MainMenu,
	Help,
	Game
};
class Game
{
public:
	Game();
	void run();
	static GameState m_currentState;


	
protected:
	void	processEvents();
	void	update(sf::Time);
	void	render();
	void    drawObjects();
	
	sf::RenderWindow m_window;
	sf::Font m_font;

	Licence m_licenceScreen;

};
#endif // !GAME_H