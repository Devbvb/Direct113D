#include "Framework.h"

Cube::Cube() : angle(0.0f)
{
	vertexShader = Shader::AddVS(L"Cube");
	pixelShader = Shader::AddPS(L"Cube");

	VertexColor vertices[8];
	vertices[0].position = { -1, 1, -1 };
	vertices[1].position = { 1, 1, -1 };
	vertices[2].position = { -1, -1, -1 };
	vertices[3].position = { 1, -1, -1 };

	vertices[4].position = { -1, 1, 1 };
	vertices[5].position = { 1, 1, 1 };
	vertices[6].position = { -1, -1, 1 };
	vertices[7].position = { 1, -1, 1 };

	vertices[0].color = { 1, 0, 0, 1 };
	vertices[1].color = { 0, 1, 0, 1 };
	vertices[2].color = { 1, 0, 1, 1 };
	vertices[3].color = { 1, 1, 0, 1 };
	vertices[4].color = { 0, 0, 1, 1 };
	vertices[5].color = { 0, 1, 1, 1 };
	vertices[6].color = { 1, 0, 1, 1 };
	vertices[7].color = { 1, 1, 0, 1 };

	UINT indices[] = {
		0, 1, 2,
		2, 1, 3,

		4, 5, 0,
		0, 5, 1,

		2, 3, 6,
		6, 3, 7,

		1, 5, 3,
		3, 5, 7,

		4, 0, 6,
		6, 0, 2,

		5, 4, 7,
		7, 4, 6
	};

	vertexBuffer = new VertexBuffer(vertices, sizeof(VertexColor), 8);
	indexBuffer = new IndexBuffer(indices, 36);
}

Cube::~Cube()
{
	delete vertexBuffer;
	delete indexBuffer;
}

void Cube::Update()
{
	static float angle = 0.0f;
	angle += 0.001f;

	world = XMMatrixRotationY(angle);

}

void Cube::Render()
{
	vertexBuffer->IASet();
	indexBuffer->IASet();
	DC->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	vertexShader->Set();
	pixelShader->Set();

	DC->DrawIndexed(36, 0, 0);
}
