#ifndef APPLICATION_H
#define APPLICATION_H

#include <MyEngine/Utils/ProjectExport.h>
#include <MyEngine/Utils/pch.h>

#include <SFML/Graphics.hpp>

#include "MyEngine/Core/Timer.h"
#include "MyEngine/Core/Layer.h"
#include "MyEngine/Scene/GameObjects/GameObject.h"

int main();

namespace MyEngine {

	/// <summary>
	/// Main Application class
	/// </summary>
	class MYENGINEAPI Application
	{
		friend int ::main();
	public:
		/// <summary>
		/// Application constructor
		/// </summary>
		/// <param name="width">Window width</param>
		/// <param name="height">Window height</param>
		/// <param name="title">Window title</param>
		/// <param name="maxFPS">Max fps in game</param>
		Application(float width, float height, const char* title);
		virtual ~Application() { delete m_Window; }

	public:
		/// <summary>
		/// Push a new Layer into the Application
		/// </summary>
		/// <param name="layer">The game layer</param>
		void pushLayer(Layer* layer);

		/// <summary>
		/// Get application istance
		/// </summary>
		/// <returns>The current application istance</returns>
		static Application& Get() { return*m_istance; }

		/// <summary>
		/// Calculate the total frames in one second by delta time
		/// </summary>
		/// <returns>Total frames</returns>
		unsigned getFrameRate()const { return 1.0f / deltaTime; }

		/// <summary>
		/// Enable FPS Limit (default true)
		/// </summary>
		void enableFPSLimit() { fpsLimitEnabled = true; }

		/// <summary>
		/// Set application max FPS
		/// </summary>
		/// <param name="maxfps"></param>
		void setMaxFPS(float maxfps) { maxFPS = maxfps; avgFPS = maxFPS; }

	private:
		/// <summary>
		/// Initialize application
		/// </summary>
		void initialize();

		/// <summary>
		/// Window app creation
		/// </summary>
		void createWindow();

		/// <summary>
		/// Main Game Loop
		/// </summary>
		void run();

		/// <summary>
		/// Updates application times at each tick
		/// </summary>
		void updateGameTime();

		/// <summary>
		/// Process Window events (resizing, closing, etc.)
		/// </summary>
		void processWindowEvents();

		/// <summary>
		/// Fixed update (by default called every 0.5 seconds)
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

		/// <summary>
		/// Calculates the avarage FPS and prints them to screen
		/// </summary>
		void trackFPS();

		/// <summary>
		/// Manage application quit and layer callback
		/// </summary>
		void applicationQuit();

	private:
		// Game Window
		sf::RenderWindow* m_Window;
		float windowWidth, windowHeight;
		const char* windowTitle;
		sf::Text windowTextFPS;
		sf::Font font;

		// Game Loop timings
		sf::Time lastTime, currentTime;
		Timer time;
		float deltaTime;
		float lag;
		unsigned maxFPS, avgFPS;
		float movAvgAlphaFPS;
		float secPerFixedUpdate;
		bool fpsLimitEnabled;

		static Application* m_istance;
		Layer* m_layer;
		std::vector<GameObject*> allEntities;
	};

	/// <summary>
	/// App creation main method (To be defined in Application implementation)
	/// </summary>
	/// <returns></returns>
	Application* createApplication();
}

#endif // !APPLICATION_H