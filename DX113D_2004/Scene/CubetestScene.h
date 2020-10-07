#pragma once

class CubetestScene : public Scene
{
private:
	Cube* cube;

	MatrixBuffer* worldBuffer;
	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;

	Matrix world;
public:
	CubetestScene();
	~CubetestScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void SetViewport();
};

