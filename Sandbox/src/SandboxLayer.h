#ifndef SANDBOX_LAYER_H
#define SANDBOX_LAYER_H

#include "MyEngine.h"

class SandboxLayer : public MyEngine::Layer
{
public:
	SandboxLayer();
	~SandboxLayer() {}

	virtual std::vector<MyEngine::GameObject*> onAttach() override;
	virtual void onDetach() override;

	void onUpdate(float deltaTime) override;
	void onEvent() override;

private:
	std::vector<MyEngine::GameObject*> allEntities;
	std::string resourcesPath = "resources/textures/";
};

#endif // !SANDBOX_LAYER_H