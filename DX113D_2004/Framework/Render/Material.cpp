#include "Framework.h"

Material::Material()
	: vertexShader(nullptr), pixelShader(nullptr)
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
	vertexShader->Set();
	pixelShader->Set();
}

void Material::SetShader(wstring file)
{
	vertexShader = Shader::AddVS(file);
	pixelShader = Shader::AddPS(file);
}
