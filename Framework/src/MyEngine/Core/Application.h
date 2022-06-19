#pragma once

#include "MyEngine/Core/ProjectExport.h"

int main();

namespace MyEngine {

	class ENGINEAPI Application
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