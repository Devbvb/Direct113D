#include "Framework.h"

Material::Material()
	: vertexShader(nullptr), pixelShader(nullptr),
	diffuseMap(nullptr)
{
}

Material::Material(wstring file)
{
	vertexShader = Shader::AddVS(file);
	pixelShader = Shader::AddPS(file);
}

Material::Material(VertexShader* vertexShader, PixelShader* pixelShader)
	: vertexShader(vertexShader), pixelShader(pixelShader)
{
}

Material::~Material()
{
}

void Material::Set()
{
	if (diffuseMap != nullptr)
		diffuseMap->PSSet(0);

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
