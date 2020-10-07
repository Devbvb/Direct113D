#include "Framework.h"

#include "Scene/CubeScene.h"
#include "Scene/CubetestScene.h"

Program::Program()
{
	Create();

	//scene = new CubeScene();
	scene = new CubetestScene();
}

Program::~Program()
{
	delete scene;

	Delete();
}

void Program::Update()
{
	scene->Update();
}

void Program::PreRender()
{
	scene->PreRender();
}

void Program::Render()
{
	Device::Get()->SetRenderTarget();

	scene->Render();
}

void Program::PostRender()
{
	scene->PostRender();
}

void Program::Create()
{
	Device::Get();
}

void Program::Delete()
{
	Device::Delete();
}
