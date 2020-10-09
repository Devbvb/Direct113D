#include "Framework.h"
#include "GridScene.h"

GridScene::GridScene()
	: width(10), height(10)
{
	material = new Material(L"Grid");

	CreateMesh();

	worldBuffer = new MatrixBuffer();
	
	fillMode[0] = new RasterizerState();
	fillMode[1] = new RasterizerState();
	fillMode[1]->FillMode(D3D11_FILL_WIREFRAME);

	texture = Texture::Add(L"Textures/background.jpg");
}

GridScene::~GridScene()
{
	delete material;
	delete mesh;
	delete worldBuffer;

	delete fillMode[0];
	delete fillMode[1];
}

void GridScene::Update()
{
}

void GridScene::PreRender()
{
}

void GridScene::Render()
{
	mesh->IASet();

	worldBuffer->SetVSBuffer(0);
	texture->PSSet(0);

	material->Set();

	//fillMode[1]->SetState();
	DC->DrawIndexed(indices.size(), 0, 0);
	//fillMode[0]->SetState();
}

void GridScene::PostRender()
{
}

void GridScene::CreateMesh()
{
	//Vertices
	for (UINT z = 0; z <= height; z++)
	{
		for (UINT x = 0; x <= width; x++)
		{
			VertexType vertex;
			vertex.position = Float3(x, 0, z);
			vertex.uv = Float2(x / (float)width, 1.0f - z / (float)height);
	

			vertices.emplace_back(vertex);
		}
	}

	//Indices
	for (UINT z = 0; z < height; z++)
	{
		for (UINT x = 0; x < width; x++)
		{
			indices.emplace_back((width + 1) * z + x); //0
			indices.emplace_back((width + 1) * (z + 1) + x); //1
			indices.emplace_back((width + 1) * (z + 1) + (x + 1)); //2

			indices.emplace_back((width + 1) * z + x); //0
			indices.emplace_back((width + 1) * (z + 1) + (x + 1)); //2
			indices.emplace_back((width + 1) * z + x + 1); //3
		}
	}

	mesh = new Mesh(vertices.data(), sizeof(VertexType), vertices.size(),
		indices.data(), indices.size());
}
