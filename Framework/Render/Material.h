#pragma once

class Material
{
private:
	class MaterialBuffer : public ConstBuffer
	{
	public:
		struct Data
		{
			Float4 diffuse;
			Float4 specular;
			Float4 ambient;

			float shininess;

			float padding[3];
		}data;

		MaterialBuffer() : ConstBuffer(&data, sizeof(Data))
		{
			data.diffuse = {1, 1, 1, 1};
			data.specular = {1, 1, 1, 1};
			data.ambient = {0.1f, 0.1f, 0.1f, 1};
			data.shininess = 24;
		}
	};

	VertexShader* vertexShader;
	PixelShader* pixelShader;

	MaterialBuffer* buffer;

	Texture* diffuseMap;
	Texture* specularMap;
public:
	Material();
	Material(wstring file);
	Material(VertexShader* vertexShader, PixelShader* pixelShader);
	~Material();

	void Set();

	void SetShader(wstring file);

	void SetDiffuseMap(wstring file);
	void SetSpecularMap(wstring file);

	MaterialBuffer* GetBuffer() { return buffer; }
};