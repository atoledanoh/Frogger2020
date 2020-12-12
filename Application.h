#pragma once
#include "PlayerControl.h"
#include "StateStack.h"
#include "SFML/System/Time.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "CommandQueue.h"

namespace Frogger
{

	class Application
	{
	public:
		Application();
		void                    run();

	private:
		void                    processInput();
		void                    update(sf::Time dt);
		void                    render();

		void                    updateStatistics(sf::Time dt);
		void                    registerStates();

	private:
		static const sf::Time   TimePerFrame;

		sf::RenderWindow        _window;
		PlayerControl           _player;
		StateStack              _stateStack;
		sf::Text                _statsText;
	};
}
