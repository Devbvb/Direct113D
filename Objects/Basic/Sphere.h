#pragma once

class Sphere : public Transform
{
private:
	typedef VertexUVNormalTangent VertexType;

	Material* material;
	Mesh* mesh;

	vector<VertexType> vertices;
	vector<UINT> indices;

	UINT sliceCount;
	UINT stackCount;
	float radius;
	
public:
	Sphere(wstring shaderFile, float radius = 1.0f, 
		UINT sliceCount = 20 , UINT stackCount = 10);
	~Sphere();

	void Update();
	void Render();

	Material* GetMaterial() { return material; }

	void CreateTangent();
private:
	void CreateMesh();
};