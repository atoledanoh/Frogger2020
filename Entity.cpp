#include "Entity.h"

namespace Frogger
{
	Entity::Entity(int hitpoints) :
		_velocity(),
		_angularVelocity(),
		_hitpoints(hitpoints)
	{}
	void Entity::setVelocity(sf::Vector2f velocity)
	{
		_velocity = velocity;
	}

	void Entity::setVelocity(float vx, float vy)
	{
		_velocity = sf::Vector2f(vx, vy);
	}

	void Entity::accelerate(sf::Vector2f velocity)
	{
		setVelocity(velocity + getVelocity());

	}

	void Entity::accelerate(float vx, float vy)
	{
		setVelocity(sf::Vector2f(vx, vy) + getVelocity());
	}

	sf::Vector2f Entity::getVelocity() const
	{
		return _velocity;
	}

	float Entity::getAngularVelocity() const
	{
		return _angularVelocity;
	}

	void Entity::setAngularVelocity(float av)
	{
		_angularVelocity = av;
	}

	void Entity::accelerateAngulaVelocity(float av)
	{
		_angularVelocity += av;
	}

	int Entity::getHitPoint() const
	{
		return _hitpoints;
	}

	void Entity::repair(int points)
	{
		_hitpoints += points;
	}

	void Entity::damage(int points)
	{
		_hitpoints -= points;
	}

	void Entity::destroy()
	{
		_hitpoints = 0;
	}

	bool Entity::isDestroyed() const
	{
		return _hitpoints <= 0;
	}

	void Entity::updateCurrent(sf::Time deltaTime, CommandQueue& commands)
	{
		move(_velocity * deltaTime.asSeconds());
		rotate(_angularVelocity * deltaTime.asSeconds());
	}
}