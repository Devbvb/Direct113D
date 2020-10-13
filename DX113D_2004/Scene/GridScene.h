#pragma once

class GridScene : public Scene
{
private:
	typedef VertexUV VertexType;

	Material* material;
	Mesh* mesh;

	vector<VertexType> vertices;
	vector<UINT> indices;

	UINT width, height;

	MatrixBuffer* worldBuffer;

	Texture* texture;

	RasterizerState* fillMode[2];
public:
	GridScene();
	~GridScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void CreateMesh();
};