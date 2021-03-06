#pragma once
#include <cmath>
#include "SFML/System/Vector2.hpp"
#include "Animation2.h"

namespace sf
{
	class Sprite;
	class Text;
}

namespace Frogger
{
	void centerOrigin(sf::Sprite& sprite);
	void centerOrigin(sf::Text& text);
	void centerOrigin(Animation2& animation);

	// trig helper function

	const float		PI = 3.14159265f;
	inline float	degreesToRadians(float degrees) { return degrees * PI / 180.f; }
	inline float	radianToDegrees(float radian) { return radian * 180.f / PI; }
	inline float	sin(float degrees) { return std::sin(degreesToRadians(degrees)); }
	inline float	cos(float degrees) { return std::cos(degreesToRadians(degrees)); }
	inline float	arctan2(float opp, float adj) { return std::atan2(opp, adj) * 180 / PI; }

	int				randomInt(int exclusiveMax);

	float			lenght(sf::Vector2f vector);
	sf::Vector2f    unitVector(sf::Vector2f vector);
}