#include "WaterLaneNode.h"
#include "DataTables.h"
#include <time.h>
#include <stdlib.h>

namespace Frogger
{
	const std::map<WaterObject::Type, WaterData> table = initializeWaterData();

	WaterLaneNode::WaterLaneNode(WaterObject::Type type) :
		_type(type),
		_time(0)
	{

		// create two water object for the begening of the game
		srand(time(NULL));
		std::unique_ptr<WaterObject> waterObj1(new WaterObject(_type));
		waterObj1->setPosition(table.at(_type).initialSpawn1);
		waterObj1->setVelocity(table.at(_type).velocity);
		attachChild(std::move(waterObj1));

		std::unique_ptr<WaterObject> waterObj2(new WaterObject(_type));
		waterObj2->setPosition(table.at(_type).initialSpawn2);
		waterObj2->setVelocity(table.at(_type).velocity);
		attachChild(std::move(waterObj2));

		initializeRandomTimeToSpan();
	}

	void WaterLaneNode::updateCurrent(sf::Time deltaTime, CommandQueue& commands)
	{
		_time += deltaTime.asSeconds();

		// check if the time is greater that the time between the creation of anoter water object
		if (_time >= _timeBeforSpanNewCar)
		{
			std::unique_ptr<WaterObject> waterObj(new WaterObject(_type));
			waterObj->setPosition(table.at(_type).spawnPosition);
			waterObj->setVelocity(table.at(_type).velocity);
			attachChild(std::move(waterObj));
			_time = 0;
			initializeRandomTimeToSpan();
		}
	}

	unsigned int WaterLaneNode::getCategory() const
	{
		return Category::Water;
	}

	void WaterLaneNode::initializeRandomTimeToSpan()
	{
		// ramdom number to be assigne to the time befor create anoter water object
		_timeBeforSpanNewCar = 5 + (rand() % (8 - 5 + 1));
	}

}