#include "Framework.h"
#include "CubeScene.h"

CubeScene::CubeScene()
{
	SetViewport();

	vertexShader = Shader::AddVS(L"Cube");
	pixelShader = Shader::AddPS(L"Cube");

	VertexColor vertices[8];
	vertices[0].position = { -1, 1, -1 };
	vertices[1].position = { 1, 1, -1 };	
	vertices[2].position = { -1, -1, -1 };	
	vertices[3].position = { 1, -1, -1 };

	vertices[4].position = { -1, 1, 1 };
	vertices[5].position = { 1, 1, 1 };
	vertices[6].position = { -1, -1, 1 };
	vertices[7].position = { 1, -1, 1 };

	vertices[0].color = { 1, 0, 0, 1 };
	vertices[1].color = { 0, 1, 0, 1 };
	vertices[2].color = { 1, 0, 1, 1 };
	vertices[3].color = { 1, 1, 0, 1 };
	vertices[4].color = { 0, 0, 1, 1 };
	vertices[5].color = { 0, 1, 1, 1 };
	vertices[6].color = { 1, 0, 1, 1 };
	vertices[7].color = { 1, 1, 0, 1 };

	UINT indices[] = {
		0, 1, 2,
		2, 1, 3,

		4, 5, 0,
		0, 5, 1,

		2, 3, 6,
		6, 3, 7,

		1, 5, 3, 
		3, 5, 7,

		4, 0, 6, 
		6, 0, 2,

		5, 4, 7,
		7, 4, 6
	};

	vertexBuffer = new VertexBuffer(vertices, sizeof(VertexColor), 8);
	indexBuffer = new IndexBuffer(indices, 36);

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

CubeScene::~CubeScene()
{
	delete vertexBuffer;
	delete indexBuffer;

	delete worldBuffer;
	delete viewBuffer;
	delete projectionBuffer;
}

void CubeScene::Update()
{
	static float angle = 0.0f;
	angle += 0.001f;

	world = XMMatrixRotationY(angle);
	
	worldBuffer->Set(world);
}

void CubeScene::PreRender()
{
}

void CubeScene::Render()
{
	vertexBuffer->IASet();
	indexBuffer->IASet();
	DC->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	worldBuffer->SetVSBUffer(0);
	viewBuffer->SetVSBUffer(1);
	projectionBuffer->SetVSBUffer(2);

	vertexShader->Set();
	pixelShader->Set();

	DC->DrawIndexed(36, 0, 0);
}

void CubeScene::PostRender()
{
}

void CubeScene::SetViewport()
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
