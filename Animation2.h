#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

namespace Frogger
{

	using Frame = sf::IntRect;

	class Animation2
	{
	public:
		Animation2(bool repeat = true);
		~Animation2();

		void						addFrame(const Frame& frame);
		void                        addFrameSet(const std::vector<Frame>);
		void						setDurationAsSeconds(float d);
		void						start();

		int							getNumberOfFrames() const;
		Frame						getFrameByNumber(int n) const;
		Frame						getCurrentFrame() const;
		Frame						update(sf::Time dt);


	private:
		std::vector<Frame>			_frames;
		std::size_t					_currentFrame;
		sf::Time					_elapsedTime;
		sf::Time					_duration;
		//sf::Time					_timePerFrame;
		bool						_repeat;

	};
}