#pragma once

class VertexShader;
class PixelShader;

class Shader
{
private:
	static map<wstring, Shader*> totalShader;

protected:
	ID3DBlob* blob;

public:
	static VertexShader* AddVS(wstring file, string entry = "VS");
	static PixelShader* AddPS(wstring file, string entry = "PS");

	static void Delete();

	virtual void Set() = 0;
};