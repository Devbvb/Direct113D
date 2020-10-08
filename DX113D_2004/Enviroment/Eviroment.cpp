#include "Framework.h"

Enviroment::Enviroment()
{
	CreatePerspective();
}

Enviroment::~Enviroment()
{
	delete viewBuffer;
	delete projectionBuffer;
}

void Enviroment::PostRender()
{
}

void Enviroment::SetViewProjection()
{
	viewBuffer->SetVSBuffer(1);
	projectionBuffer->SetVSBuffer(2);
}

void Enviroment::SetViewport(UINT width, UINT height)
{
	viewport.Width = width;
	viewport.Height = height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;

	DC->RSSetViewports(1, &viewport);
}

void Enviroment::CreatePerspective()
{

	XMVECTOR eye = XMVectorSet(5, 30, -20, 0); //카메라 위치
	XMVECTOR focus = XMVectorSet(0, 0, 0, 0); // 카메라가 바라보는 위치
	XMVECTOR up = XMVectorSet(0, 1, 0, 0); // 카메라의 업벡터

	Matrix view = XMMatrixLookAtLH(eye, focus, up);
	Matrix projection = XMMatrixPerspectiveFovLH(XM_PIDIV4,
		WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);


	viewBuffer = new MatrixBuffer();
	projectionBuffer = new MatrixBuffer();

	viewBuffer->Set(view);
	projectionBuffer->Set(projection);
}
