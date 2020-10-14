#pragma once

class Material
{
private:
	VertexShader* vertexShader;
	PixelShader* pixelShader;

	Texture* diffuseMap;

public:
	Material();
	Material(wstring file);
	Material(VertexShader* vertexShader, PixelShader* pixelShader);
	~Material();

	void Set();

	void SetShader(wstring file);

	void SetDiffuseMap(wstring file);
};