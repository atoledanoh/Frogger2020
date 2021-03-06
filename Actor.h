#pragma once

#include "Entity.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Animation2.h"
#include "TextNode.h"

#include <SFML/Graphics/Sprite.hpp>

class Actor : public Entity
{
public:

	enum class Type {
		LilyPad, Tree1, Tree2, Turtle3, Turtle2, Gator, Frog, Car1, Car2, Car3, Tractor, Truck
	};

	enum class State {
		Attack, Dead, Idle, JumpUp, JumpDown, JumpLeft, JumpRight, count
	};

	enum class Direction
	{
		Left, Right, Up, Down
	};

public:

	Actor(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts);
	~Actor() = default;

	unsigned int                        getCategory() const override;
	sf::FloatRect                       getBoundingRect() const override;
	float                               getMaxSpeed() const;

	bool                                isMarkedForRemoval() const override;

	void                                attack();
	void                                setState(State state);
	Actor::State                        getState() const;
	int                                 attackPoints() const;
	void                                hop(Direction d);

	void                                addHeart();
	void                                loseHeart();
	bool                                isAnimationFinished();



private:

	void                                updateStates();
	void                                updateCurrent(sf::Time dt, CommandQueue& commands) override;
	void                                drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	void                                updateMovementPattern(sf::Time dt);
	void                                updateTexts();


private:
	Type                                type_;
	State                               state_;
	mutable sf::Sprite                  sprite_;
	std::map<State, Animation2>         animations_;
	Direction                           direction_;
	TextNode* healthDisplay_;
	float                               travelDistance_;
	std::size_t                         directionIndex_;
	bool                                attack_;
	sf::Time                            forceFieldTimer_;
	bool                                forceField_;

	int                                 hearts;
};