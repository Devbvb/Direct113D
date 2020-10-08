#pragma once

class Cube : public Transform
{
private:
	typedef VertexColor VertexType;

	Material* material; // 셰이더 두개 합친것
	Mesh* mesh; //버퍼 두개를 합친것

	
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
