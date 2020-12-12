#include "TextureHolder.h"
#include <cassert>
#include "ResourceIdentifiers.h"

namespace Frogger
{

	TextureHolder* TextureHolder::_instance = nullptr;

	TextureHolder& TextureHolder::getInstance()
	{
		if (!TextureHolder::_instance)
			TextureHolder::_instance = new TextureHolder();

		return *TextureHolder::_instance;
	}

	void TextureHolder::load(TextureID id, const std::string& path)
	{
		std::unique_ptr<sf::Texture> texture(new sf::Texture);
		if (!texture->loadFromFile(path))
			throw std::runtime_error("Load failed - " + path);

		auto rc = _textures.insert(std::make_pair(id, std::move(texture)));
		if (!rc.second)
			assert(0);
	}

	sf::Texture& TextureHolder::get(TextureID id) const
	{
		auto found = _textures.find(id);
		assert(found != _textures.end());

		return *found->second;
	}
}