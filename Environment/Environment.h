#pragma once

class Environment : public Singleton<Environment>
{
private:	
	friend class Singleton;

	Matrix projection;
	
	MatrixBuffer* projectionBuffer;
	LightBuffer* lightBuffer;

	D3D11_VIEWPORT viewport;

	Camera* mainCamera;

	Environment();
	~Environment();

public:
	SamplerState* samplerState;

	void PostRender();

	void Set();

	void SetProjection();
	void SetViewport(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);

	Camera* GetMainCamera() { return mainCamera; }
	Matrix GetProjection() { return projection; }

private:
	void CreatePerspective();
	
};