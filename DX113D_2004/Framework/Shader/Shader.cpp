#include "Framework.h"

map<wstring, Shader*> Shader::totalShader;

VertexShader* Shader::AddVS(wstring file, string entry)
{
	wstring key = file + ToWString(entry);

	if (totalShader.count(key) > 0)
		return (VertexShader*)totalShader[key];

	totalShader[key] = new VertexShader(file, entry); // ��ĳ����

	return (VertexShader*)totalShader[key]; // �ٿ�ĳ����
}

PixelShader* Shader::AddPS(wstring file, string entry)
{
	wstring key = file + ToWString(entry);

	if (totalShader.count(key) > 0)
		return (PixelShader*)totalShader[key];

	totalShader[key] = new PixelShader(file, entry); // ��ĳ����

	return (PixelShader*)totalShader[key]; // �ٿ�ĳ����
}

void Shader::Delete()
{
	for (auto shader : totalShader)
		delete shader.second;
}
