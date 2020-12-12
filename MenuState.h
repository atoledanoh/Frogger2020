#pragma once
#include "State.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"

namespace Frogger
{

	class MenuState : public State
	{
	public:
		MenuState(StateStack& stack, Context context);

		virtual void            draw();
		virtual bool            update(sf::Time dt);
		virtual bool            handleEvent(const sf::Event& event);
		void                    updateOptionText();

	private:
		enum OptionNames
		{
			Play,
			Exit,
		};

	private:
		sf::Sprite              _backgroundSprite;

		std::vector<sf::Text>   _options;
		std::size_t             _optionIndex;
	};
}
