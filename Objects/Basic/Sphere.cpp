#include "Framework.h"

Sphere::Sphere(wstring shaderFile, float radius, UINT sliceCount, UINT stackCount)
	: radius(radius), sliceCount(sliceCount), stackCount(stackCount)
{
	material = new Material(shaderFile);
	
	CreateMesh();
}

Sphere::~Sphere()
{
	delete mesh;
	delete material;
}

void Sphere::Update()
{
	rotation.y += 0.001f;

	UpdateWorld();
}

void Sphere::Render()
{
	mesh->IASet(); // mesh 셋팅

	SetWorldBuffer(); // 월드버퍼 세팅

	material->Set(); //material 세팅

	DC->DrawIndexed((UINT)indices.size(), 0, 0); // index크기만큼 넣어서 드로우
}

void Sphere::CreateMesh()
{
	//반원을 몇개의 점으로 만들지 
	
	//각도
	float phiStep = XM_PI / stackCount;// stackCount는 가로               //XM_PI는 180도
	float thetaStep = 2.0f * XM_PI / sliceCount; //sliceCount는 세로   //XM_2PI는 360도

	//Vertex
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

			vertex.position = Vector3(vertex.normal) * radius;
			//vertex.position.x = vertex.normal.x * radius;
			//vertex.position.y = vertex.normal.y * radius;
			//vertex.position.z = vertex.normal.z * radius;

			vertex.uv.x = (float)j / sliceCount;
			vertex.uv.y = (float)i / stackCount;

			vertices.emplace_back(vertex);
		}
	}
	
	//Index
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

	//mesh 생성
	mesh = new Mesh(vertices.data(), sizeof(VertexType), (UINT)vertices.size(),
		indices.data(), (UINT)indices.size());
}
