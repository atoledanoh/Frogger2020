#pragma once
#include "Entity.h"

namespace Frogger
{

	class Vehicle : public Entity
	{
	public:
		enum Type
		{
			RaceCar1,
			RaceCar2,
			Car,
			Truck,
			Tractor
		};
	public:
		Vehicle(Type type);
		~Vehicle();

		void drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;
		sf::FloatRect									getBoundingRect() const override;
		unsigned int									getCategory() const override;

	private:
		virtual void		updateCurrent(sf::Time dt, CommandQueue& commands) override;

	private:
		Type				_type;
		sf::Sprite			_sprite;

	};
}