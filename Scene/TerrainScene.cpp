#include "Framework.h"
#include "TerrainScene.h"

TerrainScene::TerrainScene()
{
	terrain = new Terrain();
	//cube = new Cube();
	sphere = new Sphere(10);
}

TerrainScene::~TerrainScene()
{
	delete terrain;
	//delete cube;
	delete sphere;
}

void TerrainScene::Update()
{
	terrain->Update();
	//cube->Update();

	sphere->Update();
}

void TerrainScene::PreRender()
{
}

void TerrainScene::Render()
{
	terrain->Render();
	//cube->Render();
	sphere->Render();
}

void TerrainScene::PostRender()
{
}
