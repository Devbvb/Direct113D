#pragma once

class Mesh // 버텍스와 인덱스 (폴리곤의 집합)
{
private:
	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;

public:
	Mesh(void* vertexData, UINT stride, UINT vertexCount,
		void* indexData, UINT indexCount);
	~Mesh();

	void IASet(D3D11_PRIMITIVE_TOPOLOGY primitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	void UpdateVertex(void* data, UINT count);
};
