#include "Framework.h"
#include "TerrainScene.h"

TerrainScene::TerrainScene()
{
	terrain = new Terrain();
	cube = new Cube();

	terrain->GetMaterial()->SetDiffuseMap(L"Textures/Landscape/Grass_Diffuse.jpg");
	terrain->GetMaterial()->SetSpecularMap(L"Textures/Landscape/Grass_Specular.jpg");

	cube->GetMaterial()->SetDiffuseMap(L"Textures/Landscape/Marble_Diffuse.jpg");
	cube->GetMaterial()->SetSpecularMap(L"Textures/Landscape/Marble_Specular.jpg");
	cube->position = { 0, 3 ,0 };
	cube->scale = { 4, 4, 4 };


	//sphere = new Sphere(L"Specular", 3);
	//sphere->GetMaterial()->SetDiffuseMap(L"Textures/Landscape/Fieldstone_DM.tga");
	//sphere->GetMaterial()->SetSpecularMap(L"Textures/Landscape/fieldstone_SM.tga");
	//sphere->position = { 0, 3, 0 };
}

TerrainScene::~TerrainScene()
{
	delete terrain;
	delete cube;
	//delete sphere;
}

void TerrainScene::Update()
{
	terrain->Update();
	cube->Update();

	//sphere->Update();
}

void TerrainScene::PreRender()
{
}

void TerrainScene::Render()
{
	terrain->Render();
	cube->Render();
	//sphere->Render();
}

void TerrainScene::PostRender()
{
	//Cube
	ImGui::Text("CubeMaterial");
	ImGui::ColorEdit4("Diffuse", (float*)&cube->GetMaterial()->GetBuffer()->data.diffuse);
	ImGui::ColorEdit4("Specular", (float*)&cube->GetMaterial()->GetBuffer()->data.specular);
	ImGui::ColorEdit4("Ambient", (float*)&cube->GetMaterial()->GetBuffer()->data.ambient);
	ImGui::SliderFloat("Shininess", &cube->GetMaterial()->GetBuffer()->data.shininess, 1, 30);

	//Terrain
	ImGui::Text("TerrainMaterial");
	ImGui::ColorEdit4("Diffuse1", (float*)&terrain->GetMaterial()->GetBuffer()->data.diffuse);
	ImGui::ColorEdit4("Specular1", (float*)&terrain->GetMaterial()->GetBuffer()->data.specular);
	ImGui::ColorEdit4("Ambient1", (float*)&terrain->GetMaterial()->GetBuffer()->data.ambient);
	ImGui::SliderFloat("Shininess1", &terrain->GetMaterial()->GetBuffer()->data.shininess, 1, 30);
}
