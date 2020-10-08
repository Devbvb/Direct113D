#include "Framework.h"

Cube::Cube() 
{
	material = new Material(L"Cube");

	Create();
}

Cube::~Cube()
{
	delete material;
	delete mesh;
}

void Cube::Update()
{
	//rotation.x += 0.001f;
	//rotation.y += 0.001f;

	UpdateWorld();
}

void Cube::Render()
{
	mesh->IASet();

	SetWorldBuffer();

	material->Set();

	DC->DrawIndexed(indices.size(), 0, 0);
}

void Cube::Create()
{
	vertices.resize(8);
	vertices[0].position = { -1, -1, -1 };
	vertices[1].position = { -1, +1, -1 };
	vertices[2].position = { +1, +1, -1 };
	vertices[3].position = { +1, -1, -1 };

	vertices[4].position = { -1, -1, +1 };
	vertices[5].position = { -1, +1, +1 };
	vertices[6].position = { +1, +1, +1 };
	vertices[7].position = { +1, -1, +1 };

	vertices[0].color = { 1, 0, 0, 1 };
	vertices[1].color = { 0, 1, 0, 1 };
	vertices[2].color = { 0, 0, 1, 1 };
	vertices[3].color = { 1, 1, 0, 1 };
	vertices[4].color = { 1, 0, 1, 1 };
	vertices[5].color = { 0, 1, 1, 1 };
	vertices[6].color = { 1, 1, 1, 1 };
	vertices[7].color = { 0, 0, 0, 1 };

	//¾Õ¸é
	indices.emplace_back(0);
	indices.emplace_back(1);
	indices.emplace_back(2);

	indices.emplace_back(0);
	indices.emplace_back(2);
	indices.emplace_back(3);

	//¿À¸¥ÂÊ¸é
	indices.emplace_back(3);
	indices.emplace_back(2);
	indices.emplace_back(6);

	indices.emplace_back(3);
	indices.emplace_back(6);
	indices.emplace_back(7);

	//À­¸é
	indices.emplace_back(1);
	indices.emplace_back(5);
	indices.emplace_back(6);

	indices.emplace_back(1);
	indices.emplace_back(6);
	indices.emplace_back(2);

	//µÞ¸é
	indices.emplace_back(4);
	indices.emplace_back(6);
	indices.emplace_back(5);

	indices.emplace_back(4);
	indices.emplace_back(7);
	indices.emplace_back(6);

	//¿ÞÂÊ¸é
	indices.emplace_back(0);
	indices.emplace_back(5);
	indices.emplace_back(1);

	indices.emplace_back(0);
	indices.emplace_back(4);
	indices.emplace_back(5);

	//¹Ø¸é
	indices.emplace_back(0);
	indices.emplace_back(7);
	indices.emplace_back(4);

	indices.emplace_back(0);
	indices.emplace_back(3);
	indices.emplace_back(7);

	mesh = new Mesh(vertices.data(), sizeof(VertexType), vertices.size(),
		indices.data(), indices.size());

}
