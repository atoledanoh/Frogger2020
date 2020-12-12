#include "Vehicle.h"
#include "TextureHolder.h"
#include "DataTables.h"
#include "Utility.h"
#include <iostream>

namespace Frogger
{
	const std::map<Vehicle::Type, LaneData> table = initializeLaneData();

	Vehicle::Vehicle(Type type) :
		Entity(),
		_type(type),
		_sprite(TextureHolder::getInstance().get(table.at(type).texture), table.at(type).vehicleLocation)
	{
		centerOrigin(_sprite);
	}

	Vehicle::~Vehicle()
	{
		//TODO - REMOVE THIS
		std::cout << "Lane Dtor on : " << _type << std::endl;
	}

	void Vehicle::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
	{
		target.draw(_sprite, state);
	}

	sf::FloatRect Vehicle::getBoundingRect() const
	{
		return getWorldTransform().transformRect(_sprite.getGlobalBounds());
	}

	unsigned int Vehicle::getCategory() const
	{
		return Category::Track;
	}

	void Vehicle::updateCurrent(sf::Time dt, CommandQueue& commands)
	{
		// DESTROYER
		if (getPosition().x <= table.at(_type).destroyPoint.x && table.at(_type).spawnPosition.x > 480)
			destroy();
		if (getPosition().x >= table.at(_type).destroyPoint.x && table.at(_type).spawnPosition.x < 0)
			destroy();
		Entity::updateCurrent(dt, commands);
	}
}
