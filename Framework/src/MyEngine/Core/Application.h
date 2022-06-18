#pragma once

#include <iostream>

int main();

namespace MyEngine {

	class Application
	{
	public:
		// Application constructor and destructor
		Application();
		virtual ~Application() {}

		static Application& Get() { return*m_istance; }
	private:
		void Run();
	private:
		bool m_running = true;
	private:
		static Application* m_istance;
		friend int ::main();
	};

	// To be defined in Application implementation
	Application* CreateApplication();
}