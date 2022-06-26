#ifndef RENDERER2D_H
#define RENDERER2D_H

#include <MyEngine/Utils/ProjectExport.h>

#include <SFML/Graphics.hpp>

#include "MyEngine/Scene/Components/Component.h"

namespace MyEngine {

	class MYENGINEAPI Renderer2D : public MyEngine::Component
	{
		friend class Application;
	public:
		Renderer2D();
		/// <summary>
		/// Explicit Renderer2D constructor
		/// </summary>
		/// <param name="sourcePath">Texture source path</param>
		/// <param name="smooth">Texture smooth boolean</param>
		/// <param name="repeat">Texture repeat boolean</param>
		explicit Renderer2D(std::string sourcePath, bool smooth, bool repeat);
		~Renderer2D() override;

		/// <summary>
		/// Set a source path to a specific texture owner
		/// </summary>
		/// <param name="sourcePath">Texture source path</param>
		/// <param name="smooth">Texture smooth boolean</param>
		/// <param name="repeat">Texture repeat boolean</param>
		void setTextureSource(std::string sourcePath, bool smooth, bool repeat);

	private:
		sf::Texture* source;
	};
}

#endif // !RENDERER2D_H