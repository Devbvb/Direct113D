#include "Framework.h"
#include "Device.h"

Device::Device()
{
	CreateDeviceAndSwapchain();
	CreateBackBuffer();
}

Device::~Device()
{
	device->Release();
	deviceContext->Release();

	swapChain->Release();

	renderTargetView->Release();
}

void Device::CreateDeviceAndSwapchain()
{
	UINT width = WIN_WIDTH;
	UINT height = WIN_HEIGHT;

	DXGI_SWAP_CHAIN_DESC desc = {};
	desc.BufferCount = 1;
	desc.BufferDesc.Width = width;
	desc.BufferDesc.Height = height;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.BufferDesc.RefreshRate.Numerator = 60;
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = hWnd;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = true;

	V(D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		0,
		D3D11_CREATE_DEVICE_DEBUG,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&desc,
		&swapChain,
		&device,
		nullptr,
		&deviceContext
	));
}

void Device::CreateBackBuffer()
{
	ID3D11Texture2D* backBuffer;

	V(swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer));
	V(device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView));
	backBuffer->Release();

	SetRenderTarget();
}

void Device::SetRenderTarget()
{
	deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);
}

void Device::Clear(Float4 color)
{
	deviceContext->ClearRenderTargetView(renderTargetView, (float*)&color);
}

void Device::Present()
{
	swapChain->Present(0, 0);
}
