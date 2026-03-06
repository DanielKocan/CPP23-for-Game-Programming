#include <iostream>
#include <cstdint>

enum Days
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int day = Monday;

enum class Color : uint32_t // we prefering class enums!
{
	Black = 0x000000, // We are specifying the value!
	Red = 0xFF0000,
	Green = 0x00FF00,
	Blue = 0x0000FF,
	White = Red | Green | Blue
};

Color red = Color::Red;

//uint32_t green = Color::Green; // ERROR!
uint32_t green = static_cast<uint32_t>(Color::Green);
// or if we dont know type
// auto green = static_cast<std::underlying_type_t<Color>>(Color::Green);

enum class GameState
{
	MainMenu,
	Game,
	GameOver,
	HighScores
};

void doMainMenu() {} ;
void doGame() {} ;

int main()
{
	GameState gameState = GameState::MainMenu;

	switch ( gameState)
	{
	case GameState::MainMenu:
		doMainMenu();
		break;
	case GameState::Game:
		doGame();
		break;
	}

	return 0;
}