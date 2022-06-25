#ifndef ITICKABLE_H
#define ITICKABLE_H

namespace MyEngine {

	/// <summary>
	/// Interface which defines a tickable object
	/// </summary>
	class ITickable
	{
	public:
		/// <summary>
		/// Checks if object is tick-enabled
		/// </summary>
		/// <returns>tick enabled boolean</returns>
		bool tickEnabled()const { return tickable; }

		/// <summary>
		/// Enable object ticks
		/// </summary>
		void enable() { tickable = true; }

		/// <summary>
		/// Disable object ticks
		/// </summary>
		void disable() { tickable = false; }

	protected:
		/// <summary>
		/// Called on object update
		/// </summary>
		/// <param name="deltaTime">elapsed time between current and last time</param>
		virtual void onUpdate(const float deltaTime) = 0;

		/// <summary>
		/// Called on object fixed update
		/// </summary>
		/// <param name="deltaTime">elapsed time between current and last time</param>
		virtual void onFixedUpdate(const float deltaTime) = 0;

	private:
		bool tickable = true;
	};
}

#endif // !ITICKABLE_H