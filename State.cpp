#include "State.h"
#include "StateStack.h"

namespace Frogger
{

	State::Context::Context(sf::RenderWindow& window, PlayerControl& player) :
		window(&window),
		player(&player)
	{
	}


	Frogger::State::State(StateStack& stack, Context context) :
		_stack(&stack),
		_context(context)
	{
	}

	State::~State()
	{
	}

	void State::requestStackPush(StateID stateID)
	{
		_stack->pushState(stateID);
	}

	void State::requestStackPop()
	{
		_stack->popState();
	}

	void State::requestStateClear()
	{
		_stack->clearStates();
	}

	State::Context State::getContext() const
	{
		return _context;
	}
}