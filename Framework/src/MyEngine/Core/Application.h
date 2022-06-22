#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>

#include "MyEngine/Core/ProjectExport.h"
#include "MyEngine/Core/Timer.h"
#include "MyEngine/Core/Layer.h"

int main();

namespace MyEngine {

	class MYENGINEAPI Application
	{
	public:
		// Application constructor and destructor
		Application(float width, float height, const char* title);
		virtual ~Application() {}

		void pushLayer(Layer* layer);

	public:
		/// <summary>
		/// Get application istance
		/// </summary>
		/// <returns>The application</returns>
		static Application& Get() { return*m_istance; }

		/// <summary>
		/// Calculate the total frames in one second by elapsed time
		/// </summary>
		/// <returns>Total frames</returns>
		unsigned getFrameRate()const { return 1 - elapsedTime; }

		/// <summary>
		/// Limit the frame per seconds
		/// </summary>
		/// <param name="limit"></param>
		void setMaxFPS(unsigned limit) { maxFPS = limit; }

	private:
		void initApp();
		void createWindow();
		void run();
		void updateGameTime();
		void processWindowEvents();
		void fixedUpdate();
		void update();
		void draw();

	protected:
		sf::RenderWindow* m_Window;
		Timer time;
		sf::Time lastTime, currentTime;
		float elapsedTime, lag;
		unsigned maxFPS;
		float msForFixedUpdate;

		float windowWidth, windowHeight;
		const char* windowTitle;

	private:
		static Application* m_istance;
		Layer* m_layer;
		friend int ::main();
	};

	// To be defined in Application implementation
	Application* createApplication();
}

#endif // !APPLICATION_H