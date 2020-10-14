#pragma once

class Sphere : public Transform
{
private:
	typedef VertexUVNormal VertexType;

	Material* material;
	Mesh* mesh;

	vector<VertexType> vertices;
	vector<UINT> indices;

	float radius;
	UINT stackCount;
	UINT sliceCount;

public:
	Sphere(float radius, UINT stackCount = 20, UINT sliceCount = 20);
	~Sphere();

	void Update();
	void Render();

private:
	void Create();
	void CreateNormal();
};