#include <MyEngine/Utils/pch.h>

#include "MyEngine/Scene/GameObjects/GameObject.h"

namespace MyEngine {

	GameObject::GameObject(const std::string name, const bool is_active) : Object(name, is_active)
	{
		this->name = name;
		this->is_active = is_active;
	}

	GameObject::GameObject(const std::string name, const std::vector<Component*> components, const bool is_active) : Object(name, is_active)
	{
		this->name = name;
		this->components = components;
	}

	void GameObject::addComponent(Component* component)
	{
		component->owner = this;
		components.push_back(component);
	}

	void GameObject::removeComponent(Component* component)
	{
		components.erase(std::remove(components.begin(), components.end(), component), components.end());
	}

	void GameObject::onFixedUpdate(const float deltaTime)
	{
		for (auto item : components)
		{
			if (item->is_active && item->tickEnabled()) { item->onFixedUpdate(deltaTime); }
		}
	}

	void GameObject::onUpdate(const float deltaTime)
	{
		for (auto item : components)
		{
			if (item->is_active && item->tickEnabled()) { item->onUpdate(deltaTime); }
		}
	}
}