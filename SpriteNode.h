
#pragma once
#include "SceneNode.h"

namespace Frogger
{

	class SpriteNode : public SceneNode
	{
	public:
		SpriteNode(const sf::Texture&);
		SpriteNode(const sf::Texture&, sf::IntRect);

		void			drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const;

	private:
		sf::Sprite  _sprite;
	};
}