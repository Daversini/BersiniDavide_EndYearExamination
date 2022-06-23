#ifndef SANDBOX_LAYER_H
#define SANDBOX_LAYER_H

#include "MyEngine.h"

class SandboxLayer : public MyEngine::Layer
{
public:
	SandboxLayer();
	~SandboxLayer() {}

	virtual void onAttach() override;
	virtual void onDetach() override;

	void onUpdate(float deltaTime) override;
	void onEvent() override;
};

#endif // !SANDBOX_LAYER_H