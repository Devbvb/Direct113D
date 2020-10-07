#include "Framework.h"

VertexBuffer::VertexBuffer(void* data, UINT stride, UINT count)
	: stride(stride), offset(0)
{
	D3D11_BUFFER_DESC desc = {};
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.ByteWidth = stride * count;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;

	V(DEVICE->CreateBuffer(&desc, &initData, &buffer));
}

VertexBuffer::~VertexBuffer()
{
	buffer->Release();
}

void VertexBuffer::IASet()
{
	DC->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
}

void VertexBuffer::Update(void* data, UINT count)
{
	DC->UpdateSubresource(buffer, 0, nullptr, data, stride, count);
}
