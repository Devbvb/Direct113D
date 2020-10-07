#include "Framework.h"
#include "CubetestScene.h"

CubetestScene::CubetestScene()
{
	SetViewport();

	cube = new Cube();

	XMVECTOR eye = XMVectorSet(5, 5, -6, 0); //카메라 위치
	XMVECTOR focus = XMVectorSet(0, 0, 0, 0); // 카메라가 바라보는 위치
	XMVECTOR up = XMVectorSet(0, 1, 0, 0); // 카메라의 업벡터

	Matrix view = XMMatrixLookAtLH(eye, focus, up);
	Matrix projection = XMMatrixPerspectiveFovLH(XM_PIDIV4,
		WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.0f);

	worldBuffer = new MatrixBuffer();
	viewBuffer = new MatrixBuffer();
	projectionBuffer = new MatrixBuffer();

	viewBuffer->Set(view);
	projectionBuffer->Set(projection);
}

CubetestScene::~CubetestScene()
{
	delete cube;

	delete worldBuffer;
	delete viewBuffer;
	delete projectionBuffer;
}

void CubetestScene::Update()
{
	cube->Update();

	worldBuffer->Set(cube->world);
}

void CubetestScene::PreRender()
{
}

void CubetestScene::Render()
{
	worldBuffer->SetVSBUffer(0);
	viewBuffer->SetVSBUffer(1);
	projectionBuffer->SetVSBUffer(2);

	cube->Render();
}

void CubetestScene::PostRender()
{
}

void CubetestScene::SetViewport()
{
	D3D11_VIEWPORT vp;
	vp.Width = WIN_WIDTH;
	vp.Height = WIN_HEIGHT;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;

	DC->RSSetViewports(1, &vp);
}
