#include "Framework.h"

Mesh::Mesh(void* vertexData, UINT stride, UINT vertexCount, void* indexData, UINT indexCount)
{
	vertexBuffer = new VertexBuffer(vertexData, stride, vertexCount);
	indexBuffer = new IndexBuffer(indexData, indexCount);
}

Mesh::~Mesh()
{
	delete vertexBuffer;
	delete indexBuffer;
}

void Mesh::IASet(D3D11_PRIMITIVE_TOPOLOGY primitiveType)  
{
	vertexBuffer->IASet();
	indexBuffer->IASet();
	DC->IASetPrimitiveTopology(primitiveType);
}

void Mesh::UpdateVertex(void* data, UINT count)
{
	vertexBuffer->Update(data, count);
}
