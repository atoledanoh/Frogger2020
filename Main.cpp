#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>
#include "Application.h"

int main()
{
	try
	{
		Frogger::Application game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\n\nEXCEPTION: " << e.what() << std::endl;
	}
}