#pragma once

class Material
{
private:
	VertexShader* vertexShader;
	PixelShader* pixelShader;

public:
	Material();
	Material(wstring file);
	Material(VertexShader* vertexShader, PixelShader* pixelShader);
	~Material();

	void Set();

	void SetShader(wstring file);
};