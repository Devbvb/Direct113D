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

void Sphere::CreateTangent()
{
	for (UINT i = 0; i < indices.size() / 3; i++)
	{
		UINT index0 = indices[i * 3 + 0];
		UINT index1 = indices[i * 3 + 1];
		UINT index2 = indices[i * 3 + 2];

		VertexType vertex0 = vertices[index0];
		VertexType vertex1 = vertices[index1];
		VertexType vertex2 = vertices[index2];

		Vector3 p0 = vertex0.position;
		Vector3 p1 = vertex1.position;
		Vector3 p2 = vertex2.position;

		Float2 uv0 = vertex0.uv;
		Float2 uv1 = vertex1.uv;
		Float2 uv2 = vertex2.uv;

		Vector3 e0 = p1 - p0;
		Vector3 e1 = p2 - p0;

		float u0 = uv1.x - uv0.x;
		float u1 = uv2.x - uv0.x;
		float v0 = uv1.y - uv0.y;
		float v1 = uv2.y - uv0.y;

		//float d = 1.0f / (u0 * v1 - v0 * u1);		
		//Vector3 tangent = d * (v1 * e0 - v0 * e1);
		
		Vector3 tangent = (v1 * e0 - v0 * e1);

		vertices[index0].tangent = tangent + vertices[index0].tangent;
		vertices[index1].tangent = tangent + vertices[index1].tangent;
		vertices[index2].tangent = tangent + vertices[index2].tangent;
	}

	for (VertexType& vertex : vertices)
	{
		Vector3 t = vertex.tangent;
		Vector3 n = vertex.normal;

		Vector3 temp = (t - n * Vector3::Dot(n, t)).Normal();

		vertex.tangent = temp;
		
	}
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

	CreateTangent();

	//mesh ����
	mesh = new Mesh(vertices.data(), sizeof(VertexType), (UINT)vertices.size(),
		indices.data(), (UINT)indices.size());
}
