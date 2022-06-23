#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "MyEngine/Utils/ProjectExport.h"

#include "MyEngine/Core/Timer.h"
#include "MyEngine/Core/Layer.h"

int main();

namespace MyEngine {

	class MYENGINEAPI Application
	{
	public:
		/// <summary>
		/// Application constructor
		/// </summary>
		/// <param name="width">Window width</param>
		/// <param name="height">Window height</param>
		/// <param name="title">Window title</param>
		Application(float width, float height, const char* title);
		virtual ~Application() {}

		/// <summary>
		/// Push a new Layer into the Application
		/// </summary>
		/// <param name="layer">The game layer</param>
		void pushLayer(Layer* layer);

	public:
		/// <summary>
		/// Get application istance
		/// </summary>
		/// <returns>The application</returns>
		static Application& Get() { return*m_istance; }

		/// <summary>
		/// Calculate the total frames in one second by delta time
		/// </summary>
		/// <returns>Total frames</returns>
		unsigned getFrameRate()const { return 1.0f / deltaTime; }

	private:
		/// <summary>
		/// Window app creation
		/// </summary>
		void createWindow();

		/// <summary>
		/// Main Game Loop
		/// </summary>
		void run();

		/// <summary>
		/// Calculates Game time at each tick
		/// </summary>
		void updateGameTime();

		/// <summary>
		/// Process Window events (resizing, closing, etc.)
		/// </summary>
		void processWindowEvents();

		/// <summary>
		/// Fixed update (by default called every 20 seconds)
		/// </summary>
		void fixedUpdate();

		/// <summary>
		/// Main Update (called at each frame)
		/// </summary>
		void update();

		/// <summary>
		/// Update Window back and front buffers
		/// </summary>
		void render();

	protected:
		// Game Window
		sf::RenderWindow* m_Window;
		float windowWidth, windowHeight;
		const char* windowTitle;

		// Game Loop timings
		sf::Time lastTime, currentTime;
		Timer time;
		float deltaTime;
		float lag;
		unsigned maxFPS;
		bool fpsLimitEnabled;
		bool fixedUpdateEnabled;
		float SEC_PER_FIXED_UPDATE = 20;

	private:
		static Application* m_istance;
		Layer* m_layer;
		friend int ::main();
	};

	/// <summary>
	/// App creation main method (To be defined in Application implementation)
	/// </summary>
	/// <returns></returns>
	Application* createApplication();
}

#endif // !APPLICATION_H