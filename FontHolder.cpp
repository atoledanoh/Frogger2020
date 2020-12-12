#include "FontHolder.h"
#include <cassert>

namespace Frogger
{
	FontHolder* FontHolder::_instance = nullptr;

	FontHolder& FontHolder::getInstance()
	{
		if (!FontHolder::_instance)
			FontHolder::_instance = new FontHolder();

		return *FontHolder::_instance;
	}

	void FontHolder::load(FontID id, const std::string& path)
	{
		std::unique_ptr<sf::Font> texture(new sf::Font);
		if (!texture->loadFromFile(path))
			throw std::runtime_error("Load failed - " + path);

		auto rc = _fonts.insert(std::make_pair(id, std::move(texture)));
		if (!rc.second)
			assert(0);
	}

	sf::Font& FontHolder::get(FontID id) const
	{
		auto found = _fonts.find(id);
		assert(found != _fonts.end());

		return *found->second;
	}
}