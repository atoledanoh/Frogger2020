#pragma once
#include "SceneNode.h"
#include "CommandQueue.h"

namespace Frogger
{

	class Entity : public SceneNode
	{
	public:

		Entity(int hitpoints = 20);

		void             setVelocity(sf::Vector2f velocity);
		void             setVelocity(float vx, float vy);
		void			 accelerate(sf::Vector2f accelerate);
		void		     accelerate(float vx, float vy);
		sf::Vector2f     getVelocity() const;

		float			 getAngularVelocity() const;
		void			 setAngularVelocity(float av);
		void			 accelerateAngulaVelocity(float av);

		int				 getHitPoint() const;
		void			 repair(int points);
		void			 damage(int points);
		void			 destroy();
		bool		     isDestroyed() const override;

	protected:
		virtual void     updateCurrent(sf::Time deltaTime, CommandQueue& commands) override;
	private:

		sf::Vector2f     _velocity;
		float			 _angularVelocity;
		int				 _hitpoints;

	};
}