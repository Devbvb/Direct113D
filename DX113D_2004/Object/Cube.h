#pragma once

class Cube
{
private:
	VertexShader* vertexShader;
	PixelShader* pixelShader;

	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;


public:
	float angle;
	Matrix world;

public:
	Cube();
	~Cube();

	void Update();
	void Render();
};
