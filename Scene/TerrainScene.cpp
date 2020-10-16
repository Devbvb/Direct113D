#include "Framework.h"
#include "TerrainScene.h"

TerrainScene::TerrainScene()
{
	terrain = new Terrain();

	sphere = new Sphere(L"NormalMapping", 3, 50, 25);	
	sphere->GetMaterial()->SetDiffuseMap(L"Textures/Landscape/Fieldstone_DM.tga");
	sphere->GetMaterial()->SetSpecularMap(L"Textures/Landscape/Fieldstone_SM.tga");
	sphere->GetMaterial()->SetNormalMap(L"Textures/Landscape/Fieldstone_NM.tga");
	sphere->position = { 0, 3, 0 };
}

TerrainScene::~TerrainScene()
{
	delete terrain;
	//delete cube;
	delete sphere;
}

void TerrainScene::Update()
{
	if (KEY_DOWN(VK_LBUTTON))
	{
		terrain->Picking(&pickingPos);
	}

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
	//Sphere
	ImGui::Text("SphereMaterial");
	ImGui::ColorEdit4("Diffuse", (float*)&sphere->GetMaterial()->GetBuffer()->data.diffuse);
	ImGui::ColorEdit4("Specular", (float*)&sphere->GetMaterial()->GetBuffer()->data.specular);
	ImGui::ColorEdit4("Ambient", (float*)&sphere->GetMaterial()->GetBuffer()->data.ambient);
	ImGui::SliderFloat("Shininess", &sphere->GetMaterial()->GetBuffer()->data.shininess, 1, 30);

	//Cube
	/*ImGui::Text("CubeMaterial");
	ImGui::ColorEdit4("Diffuse", (float*)&cube->GetMaterial()->GetBuffer()->data.diffuse);
	ImGui::ColorEdit4("Specular", (float*)&cube->GetMaterial()->GetBuffer()->data.specular);
	ImGui::ColorEdit4("Ambient", (float*)&cube->GetMaterial()->GetBuffer()->data.ambient);
	ImGui::SliderFloat("Shininess", &cube->GetMaterial()->GetBuffer()->data.shininess, 1, 30);*/

	//Terrain
	//ImGui::Text("TerrainMaterial");
	//ImGui::ColorEdit4("Diffuse1", (float*)&terrain->GetMaterial()->GetBuffer()->data.diffuse);
	//ImGui::ColorEdit4("Specular1", (float*)&terrain->GetMaterial()->GetBuffer()->data.specular);
	//ImGui::ColorEdit4("Ambient1", (float*)&terrain->GetMaterial()->GetBuffer()->data.ambient);
	//ImGui::SliderFloat("Shininess1", &terrain->GetMaterial()->GetBuffer()->data.shininess, 1, 30);

	ImGui::Checkbox("DiffuseMap", (bool*)&sphere->GetMaterial()->GetBuffer()->data.hasDiffuseMap);
	ImGui::Checkbox("SpecularMap", (bool*)&sphere->GetMaterial()->GetBuffer()->data.hasSpecularMap);
	ImGui::Checkbox("NormalMap", (bool*)&sphere->GetMaterial()->GetBuffer()->data.hasNormalMap);

	ImGui::Text("Picking : %.1f, %.1f, %.1f", pickingPos.x, pickingPos.y, pickingPos.z);
}
