#pragma once
#include <memory>
#include <map>
#include "SFML/Graphics.hpp"
#include "ResourceIdentifiers.h"

namespace Frogger
{

	class TextureHolder
	{
	public:
		static TextureHolder& getInstance();

		void                                               load(TextureID id, const std::string& path);

		sf::Texture& get(TextureID) const;

	private:
		TextureHolder() {};  // must getInstance() to get it
	private:
		static TextureHolder* _instance;

		std::map<TextureID, std::unique_ptr<sf::Texture>>  _textures;
	};
}
