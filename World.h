#pragma once
#include "SFML/Graphics.hpp"
#include "SceneNode.h"
#include <array>
#include <vector>
#include "CommandQueue.h"
#include "Frog.h"
#include "LaneNode.h"

namespace Frogger
{

	class World
	{
	private:
		struct SpawnPoint
		{
			/*SpawnPoint(Airplaine::Type type, float _x, float _y) :
				type(type),
				x(_x),
				y(_y)
			{}
			Airplaine::Type					type;
			float							x;
			float							y;*/
		};

	public:
		/// make non-copy
		World(const World&) = delete;
		World& operator=(const World&) = delete;

		/// constructor						
		explicit							World(sf::RenderWindow& target);

		void								update(sf::Time deltaTime);

		void								draw();
		void								adapPlayerPosition();
		CommandQueue& getCommandQueue();
		bool								hasAlivePlayer();

	private:
		void								buildScene();

		sf::FloatRect						getViewBounds() const;
		sf::FloatRect						getBattleFieldBound() const;

		void								handleCollisions();
		void								updateSound();

	private:
		enum Layer
		{
			Backgroud,
			Ground,
			LayerCount
		};

	private:
		sf::RenderWindow& _window;
		sf::View								_worldView;
		SceneNode								_sceneGraph;
		std::array<SceneNode*, LayerCount>		_sceneLayers;
		CommandQueue							_commandQueue;
		//SoundPlayer&							_soundPlayer;
		sf::FloatRect							_worldBounds;
		sf::Vector2f							_spawnPosition;
		Frog* _playerFrog;
		LaneNode* _laneOne;

	};
}