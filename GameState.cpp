#include "GameState.h"

namespace Frogger
{

	GameState::GameState(StateStack& stack, Context context) :
		State(stack, context),
		_world(*context.window/*, *context.soundEffects*/),
		_player(*context.player)
	{
		//context.music->play(MusicID::MissionTheme);
	}

	void GameState::draw()
	{
		_world.draw();
	}

	bool GameState::update(sf::Time dt)
	{
		_world.update(dt);

		if (!_world.hasAlivePlayer())
		{

			requestStackPush(StateID::GameOver);
		}

		CommandQueue& commands = _world.getCommandQueue();
		_player.handleRealTimeInput(commands);

		return true;
	}

	bool GameState::handleEvent(const sf::Event& event)
	{
		CommandQueue& commands = _world.getCommandQueue();
		_player.handleEvent(event, commands);

		return true;
	}
}