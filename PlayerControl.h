#pragma once
#include "SFML/Graphics.hpp"
#include "CommandQueue.h"
#include "Command.h"
#include <map>
#include "Animation2.h"

namespace Frogger
{
	enum class Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
	};

	class PlayerControl
	{
	public:
		PlayerControl();

		void									handleEvent(const sf::Event& event, CommandQueue& commands);
		void									handleRealTimeInput(CommandQueue& commands);
	private:
		void									initializaKeyBindings();
		void									initializaActionBindings();
		bool									isRealTimeAction(Action action);


	private:
		std::map<sf::Keyboard::Key, Action>		_keyBindings;
		std::map<Action, Command>				_actionBindings;

	};

}