#pragma once

class Scene
{
private:

public:
	virtual ~Scene() = default; //virtual ~Scene() {};

	virtual void Update() = 0;
	virtual void PreRender() = 0;
	virtual void Render() = 0;
	virtual void PostRender() = 0;
};
