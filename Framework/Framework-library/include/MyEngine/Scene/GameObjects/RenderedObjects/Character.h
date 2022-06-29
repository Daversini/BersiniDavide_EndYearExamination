#ifndef CHARACTER_H
#define CHARACTER_H

#include <MyEngine/Utils/ProjectExport.h>

#include "MyEngine/Scene/GameObjects/RenderedObjects/Sprite.h"

#include "MyEngine/Scene/Components/CharacterComponents/InputController.h"
#include "MyEngine/Scene/Components/CharacterComponents/MovementComponent.h"

namespace MyEngine {
	
	/// <summary>
	/// Defines a Sprite that can be controlled with an InputController and a MovementComponent
	/// </summary>
	class MYENGINEAPI Character : public MyEngine::Sprite
	{
		friend class Application;
	public:
		Character();
		~Character() override;

	protected:
		// Inherited via ITickable
		void onUpdate(const float deltaTime) override;
		void onFixedUpdate(const float deltaTime) override;

	public:
		InputController* inputController;
		MovementComponent* movementComponent;
	};
}

#endif // !CHARACTER_H