#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

#include <MyEngine/Utils/ProjectExport.h>

#include "MyEngine/Scene/Components/Component.h"
#include "MyEngine/Scene/Components/RectTransform.h"
#include "MyEngine/Scene/Components/InputController.h"

namespace MyEngine {

	class MYENGINEAPI MovementComponent : public MyEngine::Component
	{
	public:
		MovementComponent();
		~MovementComponent() override;

		[[nodiscard]] sf::Vector2f getVelocity()const;

		[[nodiscard]] sf::Vector2f getMotionVector()const;

		[[nodiscard]] bool motionIsValid()const { return (controller->forwardMovement || controller->rightMovement); }

		// Inherited via ITickable
		void onUpdate(const float deltaTime) override;
		void onFixedUpdate(const float deltaTime) override;

	public:
		InputController* controller;
		RectTransform* transform;
		float speed;
	};
}

#endif // !MOVEMENTCOMPONENT_H