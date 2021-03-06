#pragma once

class Cube : public Transform
{
private:
	typedef VertexUVNormal VertexType;

	Material* material;
	Mesh* mesh;

	vector<VertexType> vertices;
	vector<UINT> indices;
public:
	Cube();	
	~Cube();

	void Update();
	void Render();

	Material* GetMaterial() { return material; }
private:
	void Create();
	void CreateNormal();
};