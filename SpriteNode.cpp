#include "SpriteNode.h"

namespace Frogger
{

	SpriteNode::SpriteNode(const sf::Texture& texture) :
		_sprite(texture)
	{}

	SpriteNode::SpriteNode(const sf::Texture& texture, sf::IntRect textRect) :
		_sprite(texture, textRect)
	{}

	void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const
	{
		target.draw(_sprite, state);
	}
}