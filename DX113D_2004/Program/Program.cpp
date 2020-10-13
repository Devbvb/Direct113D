#include "Framework.h"

#include "Scene/CubeScene.h"
#include "Scene/GridScene.h"

Program::Program()
{
	Create();

	//scene = new CubeScene();
	scene = new GridScene();
}

Program::~Program()
{
	delete scene;

	Delete();
}

void Program::Update()
{
	Control::Get()->Update();
	Timer::Get()->Update();

	scene->Update();

	CAMERA->Update();

	Control::Get()->SetWheel(0.0f);
}

void Program::PreRender()
{
	scene->PreRender();
}

void Program::Render()
{
	Device::Get()->SetRenderTarget();
	Environment::Get()->Set();

	scene->Render();
}

void Program::PostRender()
{
	DirectWrite::Get()->GetDC()->BeginDraw();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	wstring fps = L"FPS : " + to_wstring((int)Timer::Get()->GetFPS());
	RECT rect = { 0, 0, 100, 100 };
	DirectWrite::Get()->RenderText(fps, rect);

	Environment::Get()->PostRender();

	scene->PostRender();

	DirectWrite::Get()->GetDC()->EndDraw();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void Program::Create()
{
	Device::Get();
	Environment::Get();
	Control::Get();
	Timer::Get();
	DirectWrite::Get();

	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(hWnd);
	ImGui_ImplDX11_Init(DEVICE, DC);
}

void Program::Delete()
{
	DirectWrite::Delete();
	Timer::Delete();
	Control::Delete();
	Environment::Delete();
	Texture::Delete();
	Shader::Delete();
	Device::Delete();
}
