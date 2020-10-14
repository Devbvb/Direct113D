#pragma once

class CubeScene : public Scene
{
private:	
	Cube* sun;
	Cube* earth;
	Cube* moon;

public:
	CubeScene();
	~CubeScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
};