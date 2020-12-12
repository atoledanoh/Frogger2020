#pragma once
#include "ResourceIdentifiers.h"
#include <map>
#include <vector>
#include "Frog.h"
#include "Vehicle.h"
#include "WaterObject.h"

namespace Frogger
{

	struct Direction
	{
		Direction(float a, float b);
		float			angle;
		float			distance;
	};

	struct  FrogData
	{
		int				jump;
		TextureID		texture;
		sf::IntRect		frogLocation;
		sf::IntRect		liveLocation;
	};

	struct  LaneData
	{
		TextureID				texture;
		sf::IntRect				vehicleLocation;
		sf::Vector2f			velocity;
		sf::Vector2f			spawnPosition;
		sf::Vector2f			initialSpawn1;
		sf::Vector2f			initialSpawn2;
		sf::Vector2f			destroyPoint;
	};

	struct WaterData
	{
		TextureID				texture;
		sf::IntRect				Location;
		sf::Vector2f			velocity;
		sf::Vector2f			spawnPosition;
		sf::Vector2f			initialSpawn1;
		sf::Vector2f			initialSpawn2;
		sf::Vector2f			destroyPoint;
	};

	std::map<Frog::Type, FrogData> initializeFrogData();
	std::map<Vehicle::Type, LaneData> initializeLaneData();
	std::map<WaterObject::Type, WaterData> initializeWaterData();
}