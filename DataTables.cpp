#include "DataTables.h"
#include <functional>

namespace Frogger
{
	Direction::Direction(float a, float b) : angle(a), distance(b)
	{
	}

	std::map<Frog::Type, FrogData> initializeFrogData()
	{
		std::map<Frog::Type, FrogData> data;

		data[Frog::Type::Frogger].jump = 40;
		data[Frog::Type::Frogger].texture = TextureID::FroggerAtlas;
		data[Frog::Type::Frogger].frogLocation = sf::IntRect(61, 1, 33, 23);
		data[Frog::Type::Frogger].liveLocation = sf::IntRect(6, 1, 18, 21);

		return data;
	}

	std::map<Vehicle::Type, LaneData> initializeLaneData()
	{
		std::map<Vehicle::Type, LaneData> data;

		data[Vehicle::Type::RaceCar1].texture = TextureID::FroggerAtlas;
		data[Vehicle::Type::RaceCar1].vehicleLocation = sf::IntRect(139, 100, 38, 39);
		data[Vehicle::Type::RaceCar1].velocity = sf::Vector2f(-30.f, 0.f);
		data[Vehicle::Type::RaceCar1].spawnPosition = sf::Vector2f(500.f, 540.f);
		data[Vehicle::Type::RaceCar1].initialSpawn1 = sf::Vector2f(460.f, 540.f);
		data[Vehicle::Type::RaceCar1].initialSpawn2 = sf::Vector2f(240.f, 540.f);
		data[Vehicle::Type::RaceCar1].destroyPoint = sf::Vector2f(-20.f, 540.f);

		data[Vehicle::Type::Tractor].texture = TextureID::FroggerAtlas;
		data[Vehicle::Type::Tractor].vehicleLocation = sf::IntRect(214, 62, 33, 33);
		data[Vehicle::Type::Tractor].velocity = sf::Vector2f(50.f, 0.f);
		data[Vehicle::Type::Tractor].spawnPosition = sf::Vector2f(-20.f, 500.f);
		data[Vehicle::Type::Tractor].initialSpawn1 = sf::Vector2f(150.f, 500.f);
		data[Vehicle::Type::Tractor].initialSpawn2 = sf::Vector2f(330.f, 500.f);
		data[Vehicle::Type::Tractor].destroyPoint = sf::Vector2f(520.f, 500.f);

		data[Vehicle::Type::Car].texture = TextureID::FroggerAtlas;
		data[Vehicle::Type::Car].vehicleLocation = sf::IntRect(1, 62, 35, 29);
		data[Vehicle::Type::Car].velocity = sf::Vector2f(-25.f, 0.f);
		data[Vehicle::Type::Car].spawnPosition = sf::Vector2f(500.f, 460.f);
		data[Vehicle::Type::Car].initialSpawn1 = sf::Vector2f(264.f, 460.f);
		data[Vehicle::Type::Car].initialSpawn2 = sf::Vector2f(95.f, 460.f);
		data[Vehicle::Type::Car].destroyPoint = sf::Vector2f(-20.f, 460.f);

		data[Vehicle::Type::RaceCar2].texture = TextureID::FroggerAtlas;
		data[Vehicle::Type::RaceCar2].vehicleLocation = sf::IntRect(69, 100, 37, 37);
		data[Vehicle::Type::RaceCar2].velocity = sf::Vector2f(60.f, 0.f);
		data[Vehicle::Type::RaceCar2].spawnPosition = sf::Vector2f(-20, 420);
		data[Vehicle::Type::RaceCar2].initialSpawn1 = sf::Vector2f(355.f, 420.f);
		data[Vehicle::Type::RaceCar2].initialSpawn2 = sf::Vector2f(128.f, 420.f);
		data[Vehicle::Type::RaceCar2].destroyPoint = sf::Vector2f(520.f, 420);

		data[Vehicle::Type::Truck].texture = TextureID::FroggerAtlas;
		data[Vehicle::Type::Truck].vehicleLocation = sf::IntRect(293, 1, 61, 28);
		data[Vehicle::Type::Truck].velocity = sf::Vector2f(-70.f, 0.f);
		data[Vehicle::Type::Truck].spawnPosition = sf::Vector2f(500.f, 380.f);
		data[Vehicle::Type::Truck].initialSpawn1 = sf::Vector2f(290.f, 380.f);
		data[Vehicle::Type::Truck].initialSpawn2 = sf::Vector2f(60.f, 380.f);
		data[Vehicle::Type::Truck].destroyPoint = sf::Vector2f(-40.f, 380.f);

		return data;
	}

	std::map<WaterObject::Type, WaterData> initializeWaterData()
	{
		std::map<WaterObject::Type, WaterData> data;

		data[WaterObject::Type::Turtle3].texture = TextureID::FroggerAtlas;
		data[WaterObject::Type::Turtle3].Location = sf::IntRect(192, 1, 99, 26);
		data[WaterObject::Type::Turtle3].velocity = sf::Vector2f(-30.f, 0.f);
		data[WaterObject::Type::Turtle3].spawnPosition = sf::Vector2f(500.f, 300.f);
		data[WaterObject::Type::Turtle3].initialSpawn1 = sf::Vector2f(390.f, 300.f);
		data[WaterObject::Type::Turtle3].initialSpawn2 = sf::Vector2f(100.f, 300.f);
		data[WaterObject::Type::Turtle3].destroyPoint = sf::Vector2f(-40.f, 300.f);

		data[WaterObject::Type::Log4].texture = TextureID::FroggerAtlas;
		data[WaterObject::Type::Log4].Location = sf::IntRect(1, 31, 195, 28);
		data[WaterObject::Type::Log4].velocity = sf::Vector2f(45.f, 0.f);
		data[WaterObject::Type::Log4].spawnPosition = sf::Vector2f(-100.f, 260.f);
		data[WaterObject::Type::Log4].initialSpawn1 = sf::Vector2f(415.f, 260.f);
		data[WaterObject::Type::Log4].initialSpawn2 = sf::Vector2f(115.f, 260.f);
		data[WaterObject::Type::Log4].destroyPoint = sf::Vector2f(600.f, 260.f);

		data[WaterObject::Type::Log3].texture = TextureID::FroggerAtlas;
		data[WaterObject::Type::Log3].Location = sf::IntRect(198, 31, 93, 29);
		data[WaterObject::Type::Log3].velocity = sf::Vector2f(30.f, 0.f);
		data[WaterObject::Type::Log3].spawnPosition = sf::Vector2f(-60.f, 220.f);
		data[WaterObject::Type::Log3].initialSpawn1 = sf::Vector2f(285.f, 220.f);
		data[WaterObject::Type::Log3].initialSpawn2 = sf::Vector2f(65.f, 220.f);
		data[WaterObject::Type::Log3].destroyPoint = sf::Vector2f(600.f, 220.f);

		data[WaterObject::Type::Turtle2].texture = TextureID::FroggerAtlas;
		data[WaterObject::Type::Turtle2].Location = sf::IntRect(125, 1, 65, 26);
		data[WaterObject::Type::Turtle2].velocity = sf::Vector2f(-25.f, 0.f);
		data[WaterObject::Type::Turtle2].spawnPosition = sf::Vector2f(500.f, 180.f);
		data[WaterObject::Type::Turtle2].initialSpawn1 = sf::Vector2f(250.f, 180.f);
		data[WaterObject::Type::Turtle2].initialSpawn2 = sf::Vector2f(150, 180.f);
		data[WaterObject::Type::Turtle2].destroyPoint = sf::Vector2f(-40.f, 180.f);

		data[WaterObject::Type::Log5].texture = TextureID::FroggerAtlas;
		data[WaterObject::Type::Log5].Location = sf::IntRect(1, 31, 195, 28);
		data[WaterObject::Type::Log5].velocity = sf::Vector2f(40.f, 0.f);
		data[WaterObject::Type::Log5].spawnPosition = sf::Vector2f(-100.f, 140.f);
		data[WaterObject::Type::Log5].initialSpawn1 = sf::Vector2f(382.f, 140.f);
		data[WaterObject::Type::Log5].initialSpawn2 = sf::Vector2f(95.f, 140.f);
		data[WaterObject::Type::Log5].destroyPoint = sf::Vector2f(600.f, 140.f);

		return data;

	}
}