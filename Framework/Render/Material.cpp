#include "Framework.h"

Material::Material()
	: vertexShader(nullptr), pixelShader(nullptr),
	diffuseMap(nullptr), specularMap(nullptr)
{
	buffer = new MaterialBuffer();
}

Material::Material(wstring file)
	: diffuseMap(nullptr), specularMap(nullptr)
{
	vertexShader = Shader::AddVS(file);
	pixelShader = Shader::AddPS(file);
	buffer = new MaterialBuffer();
}

Material::Material(VertexShader* vertexShader, PixelShader* pixelShader)
	: vertexShader(vertexShader), pixelShader(pixelShader),
	diffuseMap(nullptr), specularMap(nullptr)
{
	buffer = new MaterialBuffer();
}

Material::~Material()
{
	delete buffer;
}

void Material::Set()
{
	if (diffuseMap != nullptr)
		diffuseMap->PSSet(0);

	if (specularMap != nullptr)
		specularMap->PSSet(1);

	buffer->SetPSBuffer(1);

	vertexShader->Set();
	pixelShader->Set();
}

void Material::SetShader(wstring file)
{
	vertexShader = Shader::AddVS(file);
	pixelShader = Shader::AddPS(file);
}

void Material::SetDiffuseMap(wstring file)
{
	diffuseMap = Texture::Add(file);
}

void Material::SetSpecularMap(wstring file)
{
	specularMap = Texture::Add(file);
}
