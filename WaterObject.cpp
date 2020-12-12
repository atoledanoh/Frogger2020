#include "WaterObject.h"
#include "DataTables.h"
#include "TextureHolder.h"
#include "Utility.h"
#include <iostream>

namespace Frogger
{
	const std::map<WaterObject::Type, WaterData> table = initializeWaterData();

	WaterObject::WaterObject(Type type) :
		Entity(),
		_type(type),
		_sprite(TextureHolder::getInstance().get(table.at(type).texture), table.at(type).Location)
	{
		centerOrigin(_sprite);
	}

	WaterObject::~WaterObject()
	{
		//TODO - REMOVE THIS
		std::cout << " Water Dtor on : " << _type << std::endl;
	}

	void WaterObject::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
	{
		target.draw(_sprite, state);
	}

	sf::FloatRect WaterObject::getBoundingRect() const
	{
		auto box = getWorldTransform().transformRect(_sprite.getGlobalBounds());
		box.width -= 20; // tighten up bounding box for more realistic collisions
		box.left += 10;

		return box;
	}

	unsigned int WaterObject::getCategory() const
	{
		return Category::Water;
	}

	void WaterObject::updateCurrent(sf::Time dt, CommandQueue& commands)
	{

		// DESTROYER
		if (getPosition().x <= table.at(_type).destroyPoint.x && table.at(_type).spawnPosition.x > 480)
			destroy();
		if (getPosition().x >= table.at(_type).destroyPoint.x && table.at(_type).spawnPosition.x < 0)
			destroy();
		Entity::updateCurrent(dt, commands);
	}
}
