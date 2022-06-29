#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include <MyEngine/Utils/ProjectExport.h>

#include "MyEngine/Scene/Components/Component.h"
#include "MyEngine/Scene/Components/RectTransform.h"
#include "MyEngine/Scene/Components/CharacterComponents/InputController.h"

namespace MyEngine {

	/// <summary>
	/// Defines a Component capable of calculating the movement of a Character
	/// </summary>
	class MYENGINEAPI MovementComponent : public MyEngine::Component
	{
	public:
		MovementComponent();
		~MovementComponent() override;

		/// <summary>
		/// Calculates the velocity vector
		/// </summary>
		/// <returns>Velocity</returns>
		[[nodiscard]] sf::Vector2f getVelocity()const;

		/// <summary>
		/// Calculates the motion vector
		/// </summary>
		/// <returns>Motion</returns>
		[[nodiscard]] sf::Vector2f getMotionVector()const;

		/// <summary>
		/// Checks if a character is moving
		/// </summary>
		/// <returns>Moving boolean</returns>
		[[nodiscard]] bool motionIsValid()const { return (controller->forwardMovement || controller->rightMovement); }

		// Inherited via ITickable
		void onUpdate(const float deltaTime) override;
		void onFixedUpdate(const float deltaTime) override;

	public:
		InputController* controller;
		RectTransform* transform;
		float speed;
		sf::Vector2f nextPosition;
	};
}

#endif // !MOVEMENTCOMPONENT_H