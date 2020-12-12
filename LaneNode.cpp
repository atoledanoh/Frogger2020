#include "LaneNode.h"
#include "DataTables.h"
#include <time.h>
#include <stdlib.h>
#include "Vehicle.h"


namespace Frogger
{
	const std::map<Vehicle::Type, LaneData> table = initializeLaneData();

	LaneNode::LaneNode(Vehicle::Type type) :
		_carType(type),
		_time(0)
	{

		srand(time(NULL));
		std::unique_ptr<Vehicle> vehicle1(new Vehicle(_carType));
		vehicle1->setPosition(table.at(_carType).initialSpawn1);
		vehicle1->setVelocity(table.at(_carType).velocity);
		attachChild(std::move(vehicle1));

		std::unique_ptr<Vehicle> vehicle2(new Vehicle(_carType));
		vehicle2->setPosition(table.at(_carType).initialSpawn2);
		vehicle2->setVelocity(table.at(_carType).velocity);
		attachChild(std::move(vehicle2));

		initializeRandomTimeToSpan();

	}

	void LaneNode::updateCurrent(sf::Time deltaTime, CommandQueue& commands)
	{
		_time += deltaTime.asSeconds();

		if (_time >= _timeBeforSpanNewCar)
		{
			std::unique_ptr<Vehicle> vehicle(new Vehicle(_carType));
			vehicle->setPosition(table.at(_carType).spawnPosition);
			vehicle->setVelocity(table.at(_carType).velocity);
			attachChild(std::move(vehicle));
			_time = 0;
			initializeRandomTimeToSpan();
		}
	}

	unsigned int LaneNode::getCategory() const
	{
		return Category::Track;
	}

	void LaneNode::initializeRandomTimeToSpan()
	{
		_timeBeforSpanNewCar = 4 + (rand() % (7 - 4 + 1));
	}

}