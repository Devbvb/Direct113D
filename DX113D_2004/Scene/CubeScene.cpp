#include "Framework.h"
#include "CubeScene.h"

CubeScene::CubeScene()
{
	sun = new Cube();	
	earth = new Cube();
	moon = new Cube();
	
	earth->scale = { 0.7f, 0.7f, 0.7f };
		
	moon->position = { -2, 0, 0 };
	moon->scale = { 0.5f, 0.5f, 0.5f };
}

CubeScene::~CubeScene()
{
	delete sun;
	delete earth;
	delete moon;
}

void CubeScene::Update()
{
	static float angle = 0.0f;
	angle += 0.0005f;

	
	Matrix R = XMMatrixRotationY(angle);

	static float moonAngle = 0.0f;
	moonAngle -= 0.005f;
	Matrix moonR = XMMatrixRotationY(moonAngle);

	earth->position = XMVector3TransformCoord(Vector3(3, 0, 0).data, R);

	Vector3 pos = earth->position;

	Matrix T = XMMatrixTranslation(pos.x, pos.y, pos.z);
	moon->position = XMVector3TransformCoord(Vector3(3, 0, 0).data, (moonR * T));

	sun->Update();
	earth->Update();
	moon->Update();
}

void CubeScene::PreRender()
{
}

void CubeScene::Render()
{	
	sun->Render();
	earth->Render();
	moon->Render();
}

void CubeScene::PostRender()
{
}