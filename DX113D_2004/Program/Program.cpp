#include "Framework.h"

#include "Scene/CubeScene.h"
#include "Scene/CubetestScene.h"
#include "Scene/GridScene.h"

Program::Program()
{
	Create();

	//scene = new CubeScene();
	//scene = new CubetestScene();
	scene = new GridScene();
}

Program::~Program()
{
	delete scene;

	Delete();
}

void Program::Update()
{
	Keyboard::Get()->Update();

	scene->Update();

	Camera::Get()->Update();
}

void Program::PreRender()
{
	scene->PreRender();
}

void Program::Render()
{
	Device::Get()->SetRenderTarget();
	Enviroment::Get()->SetViewport();
	Enviroment::Get()->SetViewProjection();

	Camera::Get()->SetViewport();
	Camera::Get()->SetOrthographic();

	scene->Render();
}

void Program::PostRender()
{
	Enviroment::Get()->PostRender();

	scene->PostRender();
	
	Camera::Get()->PostRender();
}

void Program::Create()
{
	Device::Get();
	Enviroment::Get();
}

void Program::Delete()
{
	Enviroment::Delete();
	Keyboard::Delete();
	Camera::Delete();
	Texture::Delete();
	Shader::Delete();
	Device::Delete();
}
