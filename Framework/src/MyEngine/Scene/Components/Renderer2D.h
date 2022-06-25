#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "MyEngine/Scene/Components/Component.h"
#include "SFML/Graphics.hpp"

namespace MyEngine {

	class Renderer2D : public Component
	{
		friend class Application;
	public:
		Renderer2D();
		explicit Renderer2D(std::string sourcePath, bool smooth, bool repeat);
		~Renderer2D() override;

		void setTextureSource(std::string sourcePath, bool smooth, bool repeat);

	private:
		sf::Texture* source;
	};
}

#endif // !RENDERER2D_H