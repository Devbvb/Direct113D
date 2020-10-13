#pragma once

class Cube : public Transform
{
private:
	typedef VertexColor VertexType;

	Material* material;
	Mesh* mesh;

	vector<VertexType> vertices;
	vector<UINT> indices;
public:
	Cube();	
	~Cube();

	void Update();
	void Render();

private:
	void Create();
};