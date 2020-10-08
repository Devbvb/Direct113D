#pragma once

class Enviroment : public Singleton<Enviroment>
{
private:
	Matrix view;
	Matrix projection;

	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;

	D3D11_VIEWPORT viewport;

public:
	Enviroment();
	~Enviroment();

	void PostRender();

	void SetViewProjection();
	void SetViewport(UINT width = WIN_WIDTH, UINT height = WIN_HEIGHT);

private:
	void CreatePerspective();
};
