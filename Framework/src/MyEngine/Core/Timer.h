#ifndef TIMER_H
#define TIMER_H

#include <SFML/System.hpp>

namespace MyEngine {

	/// <summary>
	/// Defines a structure that contains Application timings
	/// </summary>
	struct Timer
	{
	public:
		Timer() {}
		virtual ~Timer() {}

		/// <summary>
		/// Get current time
		/// </summary>
		/// <returns>Elapsed time since the last call</returns>
		sf::Time getCurrentTime()const { return clock.getElapsedTime(); }

		/// <summary>
		/// Calculate elapsed time between two instants of time
		/// </summary>
		/// <param name="currentTime"></param>
		/// <param name="lastTime"></param>
		/// <returns>Delta Time</returns>
		static float calculateElapsedTime(float currentTime, float lastTime) { return currentTime - lastTime; }

	private:
		sf::Clock clock;
	};
}

#endif // !TIMER_H