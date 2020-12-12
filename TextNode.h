#pragma once
#include "SceneNode.h"
#include "SFML/Graphics/Text.hpp"
#include <string>

namespace Frogger
{
	class TextNode : public SceneNode
	{
	public:
		explicit		TextNode(const std::string& text);

		void			setText(const std::string& text);

	private:
		void			drawCurrent(sf::RenderTarget& target, sf::RenderStates state) const override;

	private:
		sf::Text		_text;
	};
}