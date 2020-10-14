#include "Framework.h"

Sphere::Sphere(float radius, UINT stackCount, UINT sliceCount)
	: radius(radius), stackCount(stackCount), sliceCount(sliceCount)
{
	material = new Material(L"Diffuse");
	material->SetDiffuseMap(L"Textures/Landscape/Stones.png");

	Create();
}

Sphere::~Sphere()
{
	delete material;
	delete mesh;
}

void Sphere::Update()
{
	rotation.y += 0.001f;

	UpdateWorld();
}

void Sphere::Render()
{
	mesh->IASet();

	SetWorldBuffer();

	material->Set();

	DC->DrawIndexed((UINT)indices.size(), 0, 0);
}

void Sphere::Create()
{
	//반원을 몇개의 점으로 만들지
	float phiStep = PI / stackCount; 
	float thetaStep = 2.0f * PI / sliceCount;

	for (UINT i = 0; i <= stackCount; i++)
	{
		float phi = i * phiStep; // z축의 양의 방향으로부터 원점과 p가 이루는 직선을 평면에 투영시킨 직선까지의 각

		for (UINT j = 0; j <= sliceCount; j++)
		{
			float theta = j * thetaStep; // y축의 양의 방향으로 부터 원점과 p가 이루는 직선까지의 각

			/*
				x = r * sin(theta) * cos(phi)
				y = r * cos(theta)
				z = r * sin(theta) * sin(phi)
			*/ 

			VertexType vertex;

			vertex.normal.x = sin(phi) * cos(theta);
			vertex.normal.y = cos(phi);
			vertex.normal.z = sin(phi) * sin(theta);

			vertex.position.x = vertex.normal.x * radius;
			vertex.position.y = vertex.normal.y * radius;
			vertex.position.z = vertex.normal.z * radius;

			vertex.uv.x = (float)j / sliceCount;
			vertex.uv.y = (float)i / stackCount;

			vertices.emplace_back(vertex);
		}
	}

	for (UINT i = 0; i < stackCount; i++)
	{
		for (UINT j = 0; j < sliceCount; j++)
		{
			indices.emplace_back((sliceCount + 1) * i + j); // 0
			indices.emplace_back((sliceCount + 1) * i + j + 1);  // 1
			indices.emplace_back((sliceCount + 1) * (i + 1) + j);  // 2
		
			indices.emplace_back((sliceCount + 1) * (i + 1) + j); // 2
			indices.emplace_back((sliceCount + 1) * i + j + 1); // 1
			indices.emplace_back((sliceCount + 1) * (i + 1) + j + 1); // 3
		}
	}

	CreateNormal();

	mesh = new Mesh(vertices.data(), sizeof(VertexType), (UINT)vertices.size(),
		indices.data(), (UINT)indices.size());
}

void Sphere::CreateNormal()
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

		vertices[index0].normal = normal;
		vertices[index1].normal = normal;
		vertices[index2].normal = normal;
	}
}
