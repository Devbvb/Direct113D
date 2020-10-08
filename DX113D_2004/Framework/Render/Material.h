#pragma once

class Material //버텍스 픽셀 셰이더 합친 프레임워크
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
