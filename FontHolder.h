#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"
#include "ResourceIdentifiers.h"
#include <memory>
#include <map>

namespace Frogger
{

	class FontHolder
	{

	private:
		FontHolder() {};
	public:
		static FontHolder& getInstance();

		void load(FontID id, const std::string& path);
		sf::Font& get(FontID) const;


	private:
		static FontHolder* _instance;
		std::map<FontID, std::unique_ptr<sf::Font>>     _fonts;
	};
}
