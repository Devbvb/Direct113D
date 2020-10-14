#include "Framework.h"

Terrain::Terrain()
	: width(10), height(10)
{
	material = new Material(L"Diffuse");
	material->SetDiffuseMap(L"Textures/Landscape/Dirt2.png");

	fillMode[0] = new RasterizerState();
	fillMode[1] = new RasterizerState();
	fillMode[1]->FillMode(D3D11_FILL_WIREFRAME);

	heightMap = Texture::Add(L"Textures/HeightMaps/HeightMap256.png");
	
	CreateMesh();
}

Terrain::~Terrain()
{
	delete material;
	delete mesh;

	delete fillMode[0];
	delete fillMode[1];
}

void Terrain::Update()
{
	UpdateWorld();
}

void Terrain::Render()
{
	mesh->IASet();

	worldBuffer->SetVSBuffer(0);

	material->Set();

	//fillMode[1]->SetState();
	DC->DrawIndexed((UINT)indices.size(), 0, 0);
	//fillMode[0]->SetState();
}

void Terrain::CreateMesh()
{
	width = heightMap->Width() - 1;
	height = heightMap->Height() - 1;

	vector<Float4> pixels = heightMap->ReadPixels();

	//Vertices
	for (UINT z = 0; z <= height; z++)
	{
		for (UINT x = 0; x <= width; x++)
		{
			VertexType vertex;
			vertex.position = Float3((float)x, 0.0f, (float)z);
			vertex.uv = Float2(x / (float)width, 1.0f - z / (float)height);

			UINT index = (width + 1) * z + x;
			vertex.position.y += pixels[index].x * 20.0f;

			vertices.emplace_back(vertex);
		}
	}

	//Indices
	for (UINT z = 0; z < height; z++)
	{
		for (UINT x = 0; x < width; x++)
		{
			indices.emplace_back((width + 1) * z + x);//0
			indices.emplace_back((width + 1) * (z + 1) + x);//1
			indices.emplace_back((width + 1) * (z + 1) + x + 1);//2

			indices.emplace_back((width + 1) * z + x);//0
			indices.emplace_back((width + 1) * (z + 1) + x + 1);//2
			indices.emplace_back((width + 1) * z + x + 1);//3
		}
	}

	CreateNormal();

	mesh = new Mesh(vertices.data(), sizeof(VertexType), (UINT)vertices.size(),
		indices.data(), (UINT)indices.size());
}

void Terrain::CreateNormal()
{
	for (UINT i = 0; i < indices.size() / 3; i++)
	{
		UINT index0 = indices[i * 3 + 0];
		UINT index1 = indices[i * 3 + 1];
		UINT index2 = indices[i * 3 + 2];

		Vector3 v0 = vertices[index0].position;
		Vector3 v1 = vertices[index1].position;
		Vector3 v2 = vertices[index2].position;

		Vector3 A = v1 - v0;
		Vector3 B = v2 - v0;

		Vector3 normal = Vector3::Cross(A, B).Normal();

		vertices[index0].normal = (normal + vertices[index0].normal);
		vertices[index1].normal = (normal + vertices[index1].normal);
		vertices[index2].normal = (normal + vertices[index2].normal);
	}
}
