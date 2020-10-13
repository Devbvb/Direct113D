#include "Framework.h"

map<wstring, Shader*> Shader::totalShader;

VertexShader* Shader::AddVS(wstring file, string entry)
{
    wstring key = file + ToWString(entry);

    if (totalShader.count(key) > 0)
        return (VertexShader*)totalShader[key];

    totalShader[key] = new VertexShader(file, entry);

    return (VertexShader*)totalShader[key];
}

PixelShader* Shader::AddPS(wstring file, string entry)
{
    wstring key = file + ToWString(entry);

    if (totalShader.count(key) > 0)
        return (PixelShader*)totalShader[key];

    totalShader[key] = new PixelShader(file, entry);

    return (PixelShader*)totalShader[key];
}

void Shader::Delete()
{
    for (auto shader : totalShader)
        delete shader.second;
}
