#pragma once

class Material //���ؽ� �ȼ� ���̴� ��ģ �����ӿ�ũ
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
