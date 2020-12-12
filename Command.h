#pragma once
#include <cassert>
#include <functional>
#include "SFML/System/Time.hpp"

namespace Frogger
{
	class SceneNode; // forward decleration

	class Command
	{
	public:
		Command();

		std::function<void(SceneNode&, sf::Time)>   action;
		unsigned int								category;
	};

	template <typename GameObject, typename function>
	std::function<void(SceneNode&, sf::Time)>derivedAction(function fn)
	{
		return [=](SceneNode& node, sf::Time dt)
		{
			// check if downcast is safe
			assert(dynamic_cast<GameObject*>(&node) != nullptr);

			// downcast node
			fn(static_cast<GameObject&>(node), dt);
		};
	}
}