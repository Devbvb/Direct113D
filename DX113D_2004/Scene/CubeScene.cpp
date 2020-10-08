#include "Framework.h"
#include "CubeScene.h"

CubeScene::CubeScene()
{
	sun = new Cube();

	earth = new Cube();
	earth->position.x = 10.0f;
	earth->SetParent(sun->GetMatrix());
	
	moon = new Cube();
	moon->position.x = 5.0f;
	moon->SetParent(earth->GetMatrix());

}

CubeScene::~CubeScene()
{
	delete sun;
	delete earth;
	delete moon;
}

void CubeScene::Update()
{
	sun->Update();
	earth->Update();
	moon->Update();

	sun->rotation.y += 0.001f;
	earth->rotation.y += 0.001f;
	moon->rotation.y += 0.001f;
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
