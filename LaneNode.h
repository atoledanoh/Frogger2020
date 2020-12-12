#pragma once
#include "SceneNode.h"
#include "Vehicle.h"
#include <memory>

namespace Frogger
{
	class Vehicle;

	class LaneNode : public SceneNode
	{
	public:
		typedef std::unique_ptr<Vehicle> Ptr;
	public:
		LaneNode(Vehicle::Type type);
		void											updateCurrent(sf::Time deltaTime, CommandQueue& commands) override;
		unsigned int									getCategory() const override;

	private:
		void					initializeRandomTimeToSpan();
	private:
		sf::Vector2f			_spwanPosition;
		Vehicle::Type			_carType;
		float					_time;
		int						_timeBeforSpanNewCar;
		int						_min;
		int						_max;
	};
}