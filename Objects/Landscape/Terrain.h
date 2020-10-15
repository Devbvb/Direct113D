#pragma once

class Terrain : public Transform
{
private:
	typedef VertexUVNormal VertexType;

	Material* material;
	Mesh* mesh;

	vector<VertexType> vertices;
	vector<UINT> indices;

	UINT width, height;

	Texture* heightMap;

	RasterizerState* fillMode[2];

public:
	Terrain();
	~Terrain();

	void Update();	
	void Render();
	
	Material* GetMaterial() { return material; }
private:
	void CreateMesh();	
	void CreateNormal();
};

