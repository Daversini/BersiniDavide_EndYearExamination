#ifndef TIMER_H
#define TIMER_H

#include <SFML/System.hpp>

namespace MyEngine {

	struct Timer
	{
	public:
		Timer() {}
		virtual ~Timer() {}

		sf::Time getCurrentTime()const { return clock.getElapsedTime(); }

		static float calculateElapsedTime(float currentTime, float lastTime) { return currentTime - lastTime; }

	private:
		sf::Clock clock;
	};
}

#endif // !TIMER_H