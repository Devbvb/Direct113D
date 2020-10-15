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
	mesh->IASet(); // mesh ����

	SetWorldBuffer(); // ������� ����

	material->Set(); //material ����

	DC->DrawIndexed((UINT)indices.size(), 0, 0); // indexũ�⸸ŭ �־ ��ο�
}

void Sphere::CreateMesh()
{
	//�ݿ��� ��� ������ ������ 
	
	//����
	float phiStep = XM_PI / stackCount;// stackCount�� ����               //XM_PI�� 180��
	float thetaStep = 2.0f * XM_PI / sliceCount; //sliceCount�� ����   //XM_2PI�� 360��

	//Vertex
	for (UINT i = 0; i <= stackCount; i++)
	{
		float phi = i * phiStep; // z���� ���� �������κ��� ������ p�� �̷�� ������ ��鿡 ������Ų ���������� ��

		for (UINT j = 0; j <= sliceCount; j++)
		{
			float theta = j * thetaStep; // y���� ���� �������� ���� ������ p�� �̷�� ���������� ��

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

	//mesh ����
	mesh = new Mesh(vertices.data(), sizeof(VertexType), (UINT)vertices.size(),
		indices.data(), (UINT)indices.size());
}
