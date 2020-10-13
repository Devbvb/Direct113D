#pragma once

class Environment : public Singleton<Environment>
{
private:	
	Matrix projection;
	
	MatrixBuffer* projectionBuffer;

	D3D11_VIEWPORT viewport;

	Camera* mainCamera;

	SamplerState* samplerState;
public:
	Environment();
	~Environment();

	void PostRender();

	void Set();

	void SetProjection();
	void SetViewport(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);

	Camera* GetMainCamera() { return mainCamera; }
private:
	void CreatePerspective();
	
};