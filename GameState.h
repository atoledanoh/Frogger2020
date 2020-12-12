#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "World.h"
#include "PlayerControl.h"
#include "State.h"
#include "CommandQueue.h"

namespace Frogger
{

	class GameState : public State
	{
	public:
		GameState(StateStack& stack, Context context);

		virtual void        draw();
		virtual bool        update(sf::Time dt);
		virtual bool        handleEvent(const sf::Event& event);

	private:
		World               _world;
		PlayerControl& _player;

	};
}