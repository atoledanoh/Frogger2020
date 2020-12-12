#include "TextNode.h"
#include "FontHolder.h"
#include "Utility.h"

namespace Frogger
{
	TextNode::TextNode(const std::string& text) :
		_text(text, FontHolder::getInstance().get(FontID::Main), 20)
	{
		centerOrigin(_text);
	}
	void TextNode::setText(const std::string& text)
	{
		_text.setString(text);
		centerOrigin(_text);
	}
	void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(_text, states);
	}
}