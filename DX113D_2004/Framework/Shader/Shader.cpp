#include "Framework.h"

map<wstring, Shader*> Shader::totalShader;

VertexShader* Shader::AddVS(wstring file, string entry)
{
	wstring key = file + ToWString(entry);

	if (totalShader.count(key) > 0)
		return (VertexShader*)totalShader[key];

	totalShader[key] = new VertexShader(file, entry); // 업캐스팅

	return (VertexShader*)totalShader[key]; // 다운캐스팅
}

PixelShader* Shader::AddPS(wstring file, string entry)
{
	wstring key = file + ToWString(entry);

	if (totalShader.count(key) > 0)
		return (PixelShader*)totalShader[key];

	totalShader[key] = new PixelShader(file, entry); // 업캐스팅

	return (PixelShader*)totalShader[key]; // 다운캐스팅
}

void Shader::Delete()
{
	for (auto shader : totalShader)
		delete shader.second;
}
