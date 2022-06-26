#ifndef RECTTRANSFORM_H
#define RECTTRANSFORM_H

#include <MyEngine/Utils/ProjectExport.h>
#include <SFML/Graphics.hpp>

#include "MyEngine/Scene/Components/Component.h"

namespace MyEngine {
	
	/// <summary>
	/// Represents a rectangle portion of scape in the viewport
	/// </summary>
	class MYENGINEAPI RectTransform : public MyEngine::Component
	{
		friend class Application;
	public:
		RectTransform();
		/// <summary>
		/// Explicit RectTransform constructor
		/// </summary>
		/// <param name="position">Transform starting position</param>
		/// <param name="rotation">Transform starting rotation</param>
		/// <param name="scale">Trasform starting scale</param>
		explicit RectTransform(sf::Vector2f position, float rotation, sf::Vector2f scale);
		~RectTransform() override;

		/// <summary>
		/// Set area position in world space
		/// </summary>
		/// <param name="x">Horizontal position</param>
		/// <param name="y">Vertical position</param>
		void setPosition(float x, float y)const;

		/// <summary>
		/// Set area rotation in world space
		/// </summary>
		/// <param name="angle">The rotation angle in degrees</param>
		void setRotation(float angle)const;

		/// <summary>
		/// Set the area scale size in pixel in world space
		/// </summary>
		/// <param name="x">Pixel scale on X axis</param>
		/// <param name="y">Pixel scale on Y axis</param>
		void setScale(float x, float y)const;

		/// <summary>
		/// Get the transform data
		/// </summary>
		/// <returns>Rectangle area transform</returns>
		[[nodiscard]] sf::RectangleShape* getTransform()const;

	private:
		sf::Vector2f position;
		float rotation;
		sf::Vector2f scale;
		sf::RectangleShape* rectangleTransform;
	};
}

#endif // !RECTTRANSFORM_H