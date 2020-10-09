#pragma once

class Device : public Singleton<Device>
{
private:
	ID3D11Device* device; // ���ҽ� �κ�
	ID3D11DeviceContext* deviceContext; //gpu �κ� (��ºκ�)

	IDXGISwapChain* swapChain;
	ID3D11RenderTargetView* renderTargetView;

	ID3D11DepthStencilView* depthStencilView;

public:
	Device();
	~Device();

	void CreateDeviceAndSwapchain();
	void CreateBackBuffer();

	void SetRenderTarget();
	void Clear(Float4 color = Float4(0.0f, 0.125f, 0.3f, 1.0f));
	void Present();

	ID3D11Device* GetDevice() { return device; }
	ID3D11DeviceContext* GetDeviceContext() { return deviceContext; }
};

