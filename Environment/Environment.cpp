#include "Framework.h"

Environment::Environment()
{
	CreatePerspective();

	samplerState = new SamplerState();
	samplerState->SetState();

	mainCamera = new Camera();
	mainCamera->position = { 0, 5, -5 };	

	lightBuffer = new LightBuffer();
}

Environment::~Environment()
{
	delete projectionBuffer;
	delete lightBuffer;

	delete samplerState;
}

void Environment::PostRender()
{
	mainCamera->PostRender();
	ImGui::Text("LightInfo");
	ImGui::SliderFloat3("Direction", (float*)&lightBuffer->data.direction, -1, 1);
}

void Environment::Set()
{
	SetViewport();
	SetProjection();
	mainCamera->SetVS(1);
	lightBuffer->SetVSBuffer(3);
}

void Environment::SetProjection()
{	
	projectionBuffer->SetVSBuffer(2);
}

void Environment::SetViewport(UINT width, UINT height)
{
	viewport.Width = (float)width;
	viewport.Height = (float)height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;

	DC->RSSetViewports(1, &viewport);
}

void Environment::CreatePerspective()
{	
	Matrix projection = XMMatrixPerspectiveFovLH(XM_PIDIV4,
		WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

	projectionBuffer = new MatrixBuffer();
		
	projectionBuffer->Set(projection);
}
