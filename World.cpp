#include "World.h"
#include "TextureHolder.h"
#include "SpriteNode.h"
#include <math.h>
#include "ResourceIdentifiers.h"
#include <algorithm>
#include <iostream>
#include "Utility.h"
#include "DataTables.h"
#include "LaneNode.h"
#include "Vehicle.h"
#include "WaterLaneNode.h"
#include "WaterObject.h"

namespace Frogger
{
	bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);
	const std::map<Vehicle::Type, LaneData> table = initializeLaneData();

	World::World(sf::RenderWindow& window) :
		_window(window),
		_worldView(window.getDefaultView()),
		_sceneGraph(),
		_sceneLayers(),
		_commandQueue(),
		_worldBounds(0.f, 0.f, _worldView.getSize().x, _worldView.getSize().y),
		_spawnPosition(_worldView.getSize().x / 2, _worldView.getSize().y - 20),
		_playerFrog(NULL)


	{
		buildScene();

		// start the view at the bottom of the world
		//_worldView.setCenter(_spawnPosition);
	}

	void World::update(sf::Time deltaTime)
	{
		updateSound();

		while (!_commandQueue.isEmpty())
		{
			_sceneGraph.onCommande(_commandQueue.pop(), deltaTime);
		}

		handleCollisions();
		_sceneGraph.removeWercks();

		_sceneGraph.update(deltaTime, _commandQueue);
		adapPlayerPosition();
	}


	void World::draw()
	{
		_window.setView(_worldView);
		_window.draw(_sceneGraph);
	}

	void World::adapPlayerPosition()
	{
		sf::FloatRect viewBounds(_worldView.getCenter() - _worldView.getSize() / 2.f, _worldView.getSize());
		const float borderDistance = 20.f;

		sf::Vector2f position = _playerFrog->getPosition();
		position.x = std::max(position.x, viewBounds.left + borderDistance);
		position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
		position.y = std::max(position.y, viewBounds.top + borderDistance);
		position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
		_playerFrog->setPosition(position);
	}

	CommandQueue& World::getCommandQueue()
	{
		return _commandQueue;
	}

	bool World::hasAlivePlayer()
	{
		return true;
	}

	void World::buildScene()
	{
		for (std::size_t i = 0; i < LayerCount; ++i)
		{
			Category::Type category = (i == Ground) ? Category::SceneGroundLayer : Category::None;
			SceneNode::Ptr layer(new SceneNode(category));
			_sceneLayers[i] = layer.get();
			_sceneGraph.attachChild(std::move(layer));
		}

		sf::Texture& texture = TextureHolder::getInstance().get(TextureID::Background);
		sf::IntRect textureRect(0, 0, 480, 600);

		std::unique_ptr<SpriteNode> background(new SpriteNode(texture, textureRect));
		background->setPosition(_worldBounds.left, _worldBounds.top);
		_sceneLayers[Backgroud]->attachChild(std::move(background));

		std::unique_ptr<WaterLaneNode> waterOne(new WaterLaneNode(WaterObject::Type::Turtle3));
		_sceneLayers[Ground]->attachChild(std::move(waterOne));

		std::unique_ptr<WaterLaneNode> waterTwo(new WaterLaneNode(WaterObject::Type::Log4));
		_sceneLayers[Ground]->attachChild(std::move(waterTwo));

		std::unique_ptr<WaterLaneNode> waterTrree(new WaterLaneNode(WaterObject::Type::Log3));
		_sceneLayers[Ground]->attachChild(std::move(waterTrree));

		std::unique_ptr<WaterLaneNode> waterFour(new WaterLaneNode(WaterObject::Type::Turtle2));
		_sceneLayers[Ground]->attachChild(std::move(waterFour));

		std::unique_ptr<WaterLaneNode> waterFive(new WaterLaneNode(WaterObject::Type::Log5));
		_sceneLayers[Ground]->attachChild(std::move(waterFive));

		std::unique_ptr<Frog> frog(new Frog());
		_playerFrog = frog.get();
		_playerFrog->setPosition(_spawnPosition);
		_sceneLayers[Ground]->attachChild(std::move(frog));

		std::unique_ptr<LaneNode> laneOne(new LaneNode(Vehicle::Type::RaceCar1));
		_sceneLayers[Ground]->attachChild(std::move(laneOne));

		std::unique_ptr<LaneNode> laneTwo(new LaneNode(Vehicle::Type::Tractor));
		_sceneLayers[Ground]->attachChild(std::move(laneTwo));

		std::unique_ptr<LaneNode> laneThree(new LaneNode(Vehicle::Type::Car));
		_sceneLayers[Ground]->attachChild(std::move(laneThree));

		std::unique_ptr<LaneNode> laneFour(new LaneNode(Vehicle::Type::RaceCar2));
		_sceneLayers[Ground]->attachChild(std::move(laneFour));

		std::unique_ptr<LaneNode> laneFive(new LaneNode(Vehicle::Type::Truck));
		_sceneLayers[Ground]->attachChild(std::move(laneFive));
	}

	sf::FloatRect World::getViewBounds() const
	{
		return sf::FloatRect(_worldView.getCenter() - _worldView.getSize() / 2.f, _worldView.getSize());
	}

	sf::FloatRect World::getBattleFieldBound() const
	{
		sf::FloatRect bounds = getViewBounds();
		bounds.width += 40;
		return bounds;
	}

	void World::handleCollisions()
	{
		std::set<SceneNode::Pair> collisionPairs;
		_sceneGraph.checkSceneCollision(_sceneGraph, collisionPairs);

		for (auto pair : collisionPairs)
		{
			if (matchesCategories(pair, Category::Frog, Category::Track))
			{
				auto& player = static_cast<Frog&> (*pair.first);
				auto& vehicle = static_cast<Vehicle&>(*pair.second);

				_playerFrog->setPosition(_spawnPosition);
			}

			if (matchesCategories(pair, Category::Frog, Category::Water))
			{
				auto& player = static_cast<Frog&> (*pair.first);
				auto& logOrTurtle = static_cast<WaterObject&>(*pair.second);

				_playerFrog->setVelocity(logOrTurtle.getVelocity());
			}
		}

		sf::Vector2f tmp = _playerFrog->getPosition();
		if (collisionPairs.size() == 0 && _playerFrog->getPosition().y <= 300)
		{
			_playerFrog->setPosition(_spawnPosition);
			_playerFrog->setVelocity(0.f, 0.f);
		}
		if (collisionPairs.size() == 0 && _playerFrog->getPosition().y >= 340)
		{
			_playerFrog->setVelocity(0.f, 0.f);
		}

	}

	void World::updateSound()
	{
		/*_soundPlayer.setListenerPosition(_playerFrog->getWorldPosition());
		_soundPlayer.removeStoppedSounds();*/
	}

	bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
	{
		unsigned int category1 = colliders.first->getCategory();
		unsigned int category2 = colliders.second->getCategory();

		if (type1 & category1 && type2 & category2)
		{
			return true;
		}
		else if (type1 & category2 && type2 & category1)
		{
			std::swap(colliders.first, colliders.second);
			return true;
		}
		else
			return false;
	}
}