#pragma once
#include "Entity.h"
#include <vector>
#include "Animation2.h"
#include "TextNode.h"

namespace Frogger
{
	class Frog : public Entity
	{
	public:
		enum Type
		{
			Frogger
		};
		enum class State {
			Idle,
			MoveRight,
			MoveLeft,
			MoveUp,
			MoveDown,
			Dead
		};
	public:
		Frog(Type type = Type::Frogger);
		unsigned int									getCategory() const override;
		void											move(float x, float y, sf::Time dt);
		sf::FloatRect									getBoundingRect() const override;
		void											dead();

	private:
		void											drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const override;
		virtual void									updateCurrent(sf::Time dt, CommandQueue& commands) override;
		void											movementUpdate(sf::Time dt);
		void											calculateScore();
		void											updateScore();

	private:
		sf::Sprite										_sprite;
		State											_directionMove;
		mutable sf::Sprite								_livesSprite;
		sf::IntRect										_frogLocation;
		sf::IntRect										_liveLocation;
		int												_lives;
		std::map<State, std::unique_ptr<Animation2>>	_animations;
		int												_score;
		int												_lastHigherPosition;
		sf::Text 										_scoreText;
	};
}