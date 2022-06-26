#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER

#include <SFML/Graphics.hpp>

#include "MyEngine/Scene/Components/Component.h"

namespace MyEngine {

	class InputController : public MyEngine::Component
	{
		friend class Application;
		friend class MovementComponent;
	public:
		InputController();
		~InputController() override;

		/// <summary>
		/// Get a 2D vector of all the component axis
		/// </summary>
		/// <returns>Axis vector</returns>
		[[nodiscard]] sf::Vector2f getAxisVector()const { return { XAxis, YAxis }; }

	protected:
		// Inherited via ITickable
		void onUpdate(const float deltaTime) override;
		void onFixedUpdate(const float deltaTime) override;

	private:
		bool forwardMovement;
		bool rightMovement;
		float XAxis, YAxis;
	};

}

#endif // !INPUTCONTROLLER_H